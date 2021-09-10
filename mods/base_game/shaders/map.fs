#version 330 compatibility

out vec4 frag_colour;

in vec2 v_texcoord;
in vec3 v_colour;

uniform vec2 map_size;
uniform sampler2D tile_map;
uniform sampler2D tile_sheet;
uniform sampler2D water_texture;
uniform sampler2D noise_texture;
uniform sampler2D topo_texture;
uniform sampler2D terrain_texture;
uniform sampler2DArray terrain_sheet;

// https://iquilezles.org/www/articles/texturerepetition/texturerepetition.htm
vec4 noTiling(sampler2D tex, vec2 uv) {
	float k = texture(noise_texture, 0.005 * uv).x; // cheap (cache friendly) lookup
	float v = 1.;

	vec2 duvdx = dFdx(uv);
	vec2 duvdy = dFdx(uv);

	float l = k * 8.0;
	float f = fract(l);

	float ia = floor(l); // my method
	float ib = ia + 1.0;

	vec2 offa = sin(vec2(3.0, 7.0) * ia); // can replace with any other hash
	vec2 offb = sin(vec2(3.0, 7.0) * ib); // can replace with any other hash

	vec4 cola = textureGrad(tex, uv + v * offa, duvdx, duvdy);
	vec4 colb = textureGrad(tex, uv + v * offb, duvdx, duvdy);
	vec4 diff = cola - colb;
	return mix(cola, colb, smoothstep(0.2, 0.8, f - 0.1 * (diff.x + diff.y + diff.z)));
}

vec4 get_terrain(vec2 coord, vec2 offset) {
	float index = texture(terrain_texture, coord).b;
	index = trunc(index*16.);
	return texture(terrain_sheet, vec3(offset.x, offset.y, index));
}

vec4 get_terrain_mix(vec2 tex_coord) {
	vec2 pix = vec2(1.0) / map_size;
	float xx = pix.x;
	float yy = pix.y;
	vec2 scaling = mod(tex_coord + 0.5 * pix, pix) / pix;

	vec2 offset = 80. * tex_coord;
	offset.y *= xx/yy;

	vec4 color_00 = get_terrain(tex_coord + 0.5 * vec2(-xx, -yy), offset);
	vec4 color_01 = get_terrain(tex_coord + 0.5 * vec2(-xx, yy), offset);
	vec4 color_10 = get_terrain(tex_coord + 0.5 * vec2(xx, -yy), offset);
	vec4 color_11 = get_terrain(tex_coord + 0.5 * vec2(xx, yy), offset);

	vec4 color_x0 = mix(color_00, color_10, scaling.x);
	vec4 color_x1 = mix(color_01, color_11, scaling.x);

	return mix(color_x0, color_x1, scaling.y);
}

vec2 sum(vec4 v) {
	float provinceDiff = min((abs(v.x) + abs(v.y)) * 255., 1.0);
	float countryDiff = min((abs(v.z) + abs(v.w)) * 255., 1.0);
	return vec2(provinceDiff, countryDiff);
}

vec2 getBorder(vec2 texcoord) {
	// Pixel size on map texture
	vec2 pix = vec2(1.0) / map_size;

	// Noise effect
	// float x = texture(noise_texture, (1./4.) * (1./256.) * texcoord * map_size).x; // cheap (cache friendly) lookup
	// float y = texture(noise_texture, (1./4.) * (1./256.) * -texcoord * map_size).x; // cheap (cache friendly) lookup
	// texcoord += (0.5 - vec2(x, y)) * 0.5 * pix;


	vec2 mPos = texcoord - mod(texcoord + 0.5 * pix, pix);
	vec4 provienceLU = texture(tile_map, mPos + pix * vec2(0.25, 0.25)).xyzw;
	vec4 provienceLD = texture(tile_map, mPos + pix * vec2(0.25, 0.75)).xyzw;
	vec4 provienceRU = texture(tile_map, mPos + pix * vec2(0.75, 0.25)).xyzw;
	vec4 provienceRD = texture(tile_map, mPos + pix * vec2(0.75, 0.75)).xyzw;
	vec2 x0 = sum(provienceLU - provienceRU);
	vec2 x1 = sum(provienceLD - provienceRD);
	vec2 y0 = sum(provienceLU - provienceLD);
	vec2 y1 = sum(provienceRU - provienceRD);
	vec2 scaling = mod(texcoord + 0.5 * pix, pix) / pix;
	vec2 xBorder = mix(x0, x1, step(0.5, scaling.y));
	vec2 yBorder = mix(y0, y1, step(0.5, scaling.x));
	vec2 scalingE = mod(texcoord, pix) / pix;
	vec2 test = min(scalingE, vec2(1., 1.) - scalingE);
	test = 1. - 2. * test;

	vec2 xBorder2 = mix(x0, x1, scaling.y);
	vec2 yBorder2 = mix(y0, y1, scaling.x);
	vec2 diff = x0 * y0 + y0 * x1 + x1 * y1 + y1 * x0;
	diff = step(3, mod(diff + 2, 4)); // Is diag border
	vec2 borderDiag = min((xBorder2 + yBorder2) - 1.0, 2. - (xBorder2 + yBorder2));

	vec2 middle = step(0.5, x0 + y0 + x1 + y1) * min(test.x, test.y);

	vec2 border = max(xBorder * test.x, yBorder * test.y);
	border = max(border, middle);
	border = mix(border, borderDiag * 2., diff);

	border = clamp(border, 0., 1.);
	border.x *= border.x * 0.5;
	border.y *= border.y * 1.2;
	vec2 tiled = step(pix, mod(texcoord + pix * 0.5, pix * 2));
	border.y *= (tiled.x + tiled.y) * (2. - (tiled.x + tiled.y));
	return border;
}

void main() {
	const vec4 land = vec4(0., 0.7, 0., 1.);
	const vec4 province_border = vec4(0., 0., 0., 1.);
	const vec4 country_border = vec4(0.8, 0., 0., 1.);
	const vec4 mountain = vec4(0., 0., 0., 1.);
	const vec4 water_col = vec4(0.06, 0.39, 0.75, 1.);

	vec4 water = noTiling(water_texture, 50. * v_texcoord);
	water = mix(water, water_col * 0.7, 0.7);
	// water.rgb = water.rgb * 1.2 - 0.4;

	vec4 terrain_color = get_terrain_mix(v_texcoord);

	float height = texture(topo_texture, v_texcoord).x;

	vec4 coord = texture(tile_map, v_texcoord).rgba;
	vec4 ground = mix(water, terrain_color, step(0.08, height));
	vec4 prov_colour = texture(tile_sheet, coord.rg);
	vec4 out_colour = mix(ground, prov_colour, 0.8 * step(coord.a, 0.01) * prov_colour.a);
	out_colour = mix(out_colour, mountain, height * height * 1.5 + 0.2);

	vec2 borders = getBorder(v_texcoord);
	out_colour = mix(out_colour, province_border, borders.x);
	out_colour = mix(out_colour, country_border, borders.y);
	frag_colour = out_colour;
}

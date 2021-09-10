#version 330 compatibility

out vec4 frag_colour;

in vec2 v_texcoord;
in vec3 v_colour;

uniform float step;
uniform sampler2D map;

void main() {
	const vec4 land = vec4(0., 0.7, 0., 1.);

	vec4 fragData0;
	vec4 neighbor0;
	vec2 nCoord[8];

	float dist = 0.0;
	float newDist;
	int i;

	nCoord[0] = vec2( v_texcoord.s - step, v_texcoord.t - step );
	nCoord[1] = vec2( v_texcoord.s       , v_texcoord.t - step );
	nCoord[2] = vec2( v_texcoord.s + step, v_texcoord.t - step );
	nCoord[3] = vec2( v_texcoord.s - step, v_texcoord.t        );
	nCoord[4] = vec2( v_texcoord.s + step, v_texcoord.t        );
	nCoord[5] = vec2( v_texcoord.s - step, v_texcoord.t + step );
	nCoord[6] = vec2( v_texcoord.s       , v_texcoord.t + step );
	nCoord[7] = vec2( v_texcoord.s + step, v_texcoord.t + step );

	fragData0  = texture2DRect( map, v_texcoord.st );

	if( fragData0.a == 1.0 )
		dist = length(fragData0.rg-v_texcoord.st);

	for( i = 0; i < 8; ++i )
	{
		if( nCoord[i].s < 0.0 || nCoord[i].s >= width || nCoord[i].t < 0.0 || nCoord[i].t >= height )
			continue;

		neighbor0 = texture2DRect( map, nCoord[i] );

		if( neighbor0.a != 1.0 )
			continue;

		newDist = length(neighbor0.rg-v_texcoord.st);

		if( fragData0.a != 1.0 || newDist < dist ) {
			fragData0 = neighbor0;
			dist = newDist;
		}
	}

	frag_colour = fragData[0];
}
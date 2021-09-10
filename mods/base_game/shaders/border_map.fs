#version 330 compatibility

out vec4 frag_colour;

in vec2 v_texcoord;
in vec3 v_colour;

uniform sampler2D tile_map;
uniform sampler2D tile_sheet;

void main() {
	const vec4 land = vec4(0., 0.7, 0., 1.);

	frag_colour = land;
}

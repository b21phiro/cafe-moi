uniform sampler2D u_texture;

uniform vec4 u_color1;
uniform vec4 u_color2;

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    vec4 pixel = texture2D(u_texture, uv);

    vec3 result = mix(u_color1.rgb, u_color2.rgb, pixel.r);

    gl_FragColor = vec4(result, pixel.a);
}
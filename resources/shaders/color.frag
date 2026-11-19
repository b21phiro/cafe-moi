uniform sampler2D u_texture;

uniform vec4 u_color1;

uniform vec4 u_color2;
uniform bool u_use_color2;

uniform vec4 u_color3;
uniform bool u_use_color3;

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    vec4 pixel = texture2D(u_texture, uv);

    // Replace transparent texture pixels with color3
    if (u_use_color3 && pixel.a == 0.0)
    {
        gl_FragColor = u_color3;
        return;
    }

    vec3 result = u_color1.rgb;

    if (u_use_color3)
    {
        if (pixel.r < 0.5)
        result = mix(u_color1.rgb, u_color3.rgb, pixel.r * 2.0);
        else
        result = mix(u_color3.rgb, u_color2.rgb, (pixel.r - 0.5) * 2.0);
    }
    else if (u_use_color2)
    {
        result = mix(u_color1.rgb, u_color2.rgb, pixel.r);
    }

    gl_FragColor = vec4(result, pixel.a);
}
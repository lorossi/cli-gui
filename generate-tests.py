def format_color(color):
    to_remove = ["fg_", "bg_"]

    for r in to_remove:
        color = color.replace(r, "")

    color = color.replace("_", " ")
    color = color.lower()

    return f"Color: {color}"


def main():
    fg = [
        "fg_BLACK",
        "fg_RED",
        "fg_GREEN",
        "fg_YELLOW",
        "fg_BLUE",
        "fg_MAGENTA",
        "fg_CYAN",
        "fg_WHITE",
        "fg_DEFAULT"]

    bright_fg = [
        "fg_BRIGHT_BLACK",
        "fg_BRIGHT_RED",
        "fg_BRIGHT_GREEN",
        "fg_BRIGHT_YELLOW",
        "fg_BRIGHT_BLUE",
        "fg_BRIGHT_MAGENTA",
        "fg_BRIGHT_CYAN",
        "fg_BRIGHT_WHITE",
    ]

    bg = [
        "bg_BLACK",
        "bg_RED",
        "bg_GREEN",
        "bg_YELLOW",
        "bg_BLUE",
        "bg_MAGENTA",
        "bg_CYAN",
        "bg_WHITE",
        "bg_DEFAULT"]

    bright_bg = [
        "bg_BRIGHT_BLACK",
        "bg_BRIGHT_RED",
        "bg_BRIGHT_GREEN",
        "bg_BRIGHT_YELLOW",
        "bg_BRIGHT_BLUE",
        "bg_BRIGHT_MAGENTA",
        "bg_BRIGHT_CYAN",
        "bg_BRIGHT_WHITE"
    ]

    spacing = 1

    c_code = ""
    c_code += " /* test foreground colors */\n"
    for i, color in enumerate(fg):
        f_color = format_color(color)

        if len(f_color) > spacing:
            spacing = len(f_color) + 1

        c_code += f"move_cursor_to(0, {i});\n"
        c_code += f"set_fg({color});\n"

        c_code += f"printf(\"{f_color}\");\n\n"

    for i, color in enumerate(bright_fg):
        f_color = format_color(color)

        c_code += f"move_cursor_to({spacing}, {i});\n"
        c_code += f"set_fg({color});\n"
        c_code += f"printf(\"{f_color}\");\n\n"

    spacing = 1

    c_code += "reset_fg();\n"
    c_code += " /* test background colors */\n"
    for i, color in enumerate(bg):
        f_color = format_color(color)

        if len(f_color) > spacing:
            spacing = len(f_color) + 1

        c_code += f"move_cursor_to(0, {i+9});\n"
        c_code += f"set_bg({color});\n"
        c_code += f"printf(\"{f_color}\");\n\n"

    for i, color in enumerate(bright_bg):
        f_color = format_color(color)

        c_code += f"move_cursor_to({spacing}, {i+9});\n"
        c_code += f"set_bg({color});\n"
        c_code += f"printf(\"{f_color}\");\n\n"

    c_code += "printf(\"\\n\");\n"

    print(c_code, end="")


if __name__ == "__main__":
    main()

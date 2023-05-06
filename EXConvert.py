def convert_bytes(bytes_number):
    tags = ["Byte", "Kilobyte", "Megabyte", "Gigabyte", "Terabyte",
            "Petabyte", "Exabyte", "Zettabyte", "Yottabyte"]

    i = 0
    double_bytes = bytes_number

    while (i < len(tags) and bytes_number >= 1024):
        double_bytes = bytes_number / 1024.0
        i = i + 1
        bytes_number = bytes_number / 1024

    return "Round: " + str(round(double_bytes, 2)) + " " + tags[i] + "\nExact: " + str(double_bytes) + " " + tags[i]


def convert_exords(exords_number):
    tags = ["Exord", "Kiloexord", "Megaexord", "Gigaexord",
            "Teraexord", "Petaexord", "Exaexcord", "Zettaexord", "Yottaexord"]

    i = 0
    double_exords = exords_number

    while (i < len(tags) and exords_number >= 5):
        double_exords = exords_number / 5.0
        i = i + 1
        exords_number = exords_number / 5

    return "Round: " + str(round(double_exords, 2)) + " " + tags[i] + "\nExact: " + str(double_exords) + " " + tags[i]


def convert_bytetoexord(bytetoexord_number):
    return convert_exords(bytetoexord_number/104)


def convert_exordtobyte(exordtobyte_number):
    return convert_bytes(exordtobyte_number*104)


print(convert_exordtobyte(300))
input()

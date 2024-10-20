import binascii

def convert(fileName:str, HeaderName: str, dataName: str) -> None:

    with open(fileName, "rb") as file:
        data = file.read()

    with open(f"{HeaderName}", "w") as file:
        # Convert to hexadecimal format
        hex_data = binascii.hexlify(data).decode()

        # Split the hex data into bytes (2 characters each)
        split_data = [hex_data[i:i+2] for i in range(0, len(hex_data), 2)]

        # Join the elements with '0x' prefix and commas
        formatted_data = ", ".join(f"0x{byte}" for byte in split_data)

        # Create the C-style array declaration
        c_style_array = f"const char {dataName}[] = {{ {formatted_data} }};"

        # Print and write to file
        print(c_style_array)
        file.write(c_style_array)

convert("src/default.vert", "src/vertexData.h", "vertexData")
convert("src/default.frag", "src/fragData.h", "fragData")
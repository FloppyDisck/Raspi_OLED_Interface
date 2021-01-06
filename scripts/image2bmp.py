from PIL import Image

def image2binary(image):
    #Check if image is propper size

    pix = image.load()

    if (image.size[0] % 8 == 0):
        binary = []
        for y in range(image.size[1]):
            for x in range(image.size[0]):
                if (pix[x,y][:3] == (0,0,0)):
                    binary.append(1)
                else:
                    binary.append(0)
                print(binary[-1], end='')
            print('')#new line
        # print image size
        print(f"Width={image.size[0]}\nHeight={image.size[1]}")
        return binary
    else:
        print("Image width must be divisible by 8")

def binary2bmp(binary):
    binary_bytes = []
    bmpSize = 0
    if (len(binary) % 8 == 0):
        for i in range(int(len(binary) / 8)):
            binary_bytes.append(hex(int(binary[i*8:(i+1)*8], 2)))
            bmpSize+=1
    else:
        print("Total bits non divisible by 8")

    print(f"BMPSize={bmpSize}")

    return binary_bytes

def list2str(arr):
    strng = ""
    for i in arr:
        strng += str(i)
    return strng

if __name__ == "__main__":
    import sys

    image_file = sys.argv[1]

    #Reverse string and split file from path, fix string
    try:
        file_path = image_file[::-1].split('/',1)[1][::-1] + "/"
    except IndexError as e:
        file_path = ""

    img = Image.open(image_file)

    binary_bytes = binary2bmp(list2str(image2binary(img)))

    with open(file_path+"out.txt", 'w') as f:
        byte_string = ""
        for i in binary_bytes:
            byte_string += i + ", "
        f.write(byte_string)
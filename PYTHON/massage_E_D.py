# massage encoder - decoder

def encode(massage):                        #encoder
    ch = int(input("1-10 any code : "))
    en_str = ch
    print(en_str)
    match ch :
        case 1:
            for c in massage:
                en_str += chr(ord(c) - 19)
                print(en_str,end="")
        case 2:
            for c in massage:
                en_str += (c + '*')
        # case 3:
        #     for c in massage:

        case _:
            print("working progress!!!")
    return en_str

def decode(massage):                        #decoder
    de_str = ""
    ch = int(massage[0])
    match ch:
        case 1:
            for c in massage[1:]:
                de_str += chr(ord(c) + 19)
        case 2:
            for c in massage:
                if c != '*':
                    de_str += c
        case _:
            print("working progess !!!")
    return de_str


ch = int(input("1. Encode \n2. Decode \nchioce :: "))
match ch:
    case 1:
        massage = input("Type your massage -> ")
        em = encode(massage)
        # print(em)
    case 2:
        massage = input("Type your massage -> ")
        dm = decode(massage)
        print(dm)
    case _:
        print("Invalid !")
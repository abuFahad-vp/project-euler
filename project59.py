# http://radiusofcircle.blogspot.com

# time module
import time

# time at the start of program execution
start = time.time()


def check_english(ascii1, ascii2):
    """
    function to check if the
    xor(exclusive or) of two ascii
    numbers entered is only letters
    used in common english
    """
    xor = ascii1 ^ ascii2
    if 32 <= xor <= 90:
        return True
    elif 97 <= xor <= 122:
        return True
    return False


def decrypt(s, t):
    """
    This function will take a ascii value and
    a string(the key) and xor with the encrypted text
    and find the real solution
    """
    return ''.join(chr(a ^ ord(b)) for a, b in zip(s, t))

# open the file
f = open('project59.txt')

# Strip and split the contents of the file to a list
cipher = f.read().strip().split(',')

# convert the string to integer
cipher = [int(x) for x in cipher]

# letters in ascii from a-z
eng_letters = range(97, 123)

# first letter of the encryption key
first_letter = set([])

# for loop to loop through a-z and cipher text
for j in eng_letters:
    for i in range(0, len(cipher), 3):
        first_letter.add(j)
        if not check_english(cipher[i], j):
            first_letter.remove(j)
            break

# second letter of the encryption key
second_letter = set([])

# for loop to loop through a-z and cipher text
for j in eng_letters:
    for i in range(1, len(cipher), 3):
        second_letter.add(j)
        if not check_english(cipher[i], j):
            second_letter.remove(j)
            break

# third character of the encryption key
third_letter = set([])

# for loop to loop through a-z and cipher text
for j in eng_letters:
    for i in range(2, len(cipher), 3):
        third_letter.add(j)
        if not check_english(cipher[i], j):
            third_letter.remove(j)
            break

# conver the first letter from ascii to character
first_letter = chr(list(first_letter)[0])

# convert the second letter from ascii to character
second_letter = chr(list(second_letter)[0])

# convert the third letter from ascii to character
third_letter = chr(list(third_letter)[0])

# string concatenation to find the encrypt key
encrypt_key = first_letter+second_letter+third_letter

# variable to store the decrypted string
plain_text = ''

# looping through the cipher text
for i in range(0, len(cipher), 3):
    plain_text += decrypt(cipher[i:i+3], encrypt_key)

# printing the sum of characters
print(sum(map(ord, plain_text)))

# time at the end of program execution
end = time.time()

# printing the total time of execution
print(end - start)
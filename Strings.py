#PYTHON, BASICLY, HAS A SET OF FUNCTIONS TO STRING MANIPULATION
#YOU CAN USE IT FOR VERIFICATION && ANALYZE || FORMAT && MODIFY THE STRING

string = "banana"
bigger_string =  "I am Pichara"
array_string = ["I","am", "Pichara"]

#Modification
print("\nMODIFICATION\n")


print("banana.upper: ", string.upper())

print("banana.lower: ", string.lower())

print("banana.capitalize: ", string.capitalize())


#Verification
print("\nVERIFICATION\n")


print("banana.islower: ", string.islower())

print("banana.isupper: ", string.isupper())

print("banana.isalpha: ", string.isalpha()) #Returns True if every char is a letter

print("banana.isnumeric: ", string.isnumeric()) #Returns True if every char is a number

print("banana.isalnum: ", string.isalnum()) #Returns True if every char is only letter or number


#Analyze
print("\nANALYZE\n")


print("banana.count(): ", string.count("a")) #Return a Int counting how many times the char appeared 

print("banana.find(): ", string.find("a")) #Returns the first index of the char in the string  

print("banana.rfind(): ", string.rfind("a")) #Returns the last index of the char in the string

#Formating
print("\nFORMATING\n")

for letter in string:
    print(letter)

print("banana[2:5]: ", string[2:5])

print("banana[1:6:2]: ", string[1:6:2])

print("     banana.strip(): ", "   banana".strip()) #Remove spaces in front and before the string but not in the between

print("banana.replace('banana', 'orange'): ", string.replace("banana", "orange")) #Replaces one item for other in the string

print("I am Pichara.split(""): ", bigger_string.split(" ")) #Transforms the string in a list, based in the charecthers that you passed to it

print("'_'.join(['I','am','Pichara']): ", "_".join(array_string)) #Transform a array of strings into a string filling the gap with the element that you putin the paramether

print(f"My name is {array_string[2]}") 

#If I want for example to find the value 7 in ORDERED array, I can use binary search for less memory usage!
#Of course you can use index() in python, but this is a linear search

#You can do the binary search like this:
array = [1, 3, 4, 6, 7, 9, 10, 12, 14, 15, 17, 19, 21, 23, 25, 27, 28, 30, 31]
number = 31 

start_of_array = 0
end_of_array = len(array) - 1

while start_of_array <= end_of_array:
    mid_index = (start_of_array + end_of_array) // 2
    
    if array[mid_index] == number:
        print(f"Number is in the index: {mid_index}")
        break
    elif number < array[mid_index]:
        end_of_array = mid_index - 1
    else:
        start_of_array = mid_index + 1
else:
    print("Number not found!")

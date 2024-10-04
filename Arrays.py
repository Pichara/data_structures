import numpy as np
# A ARRAY MUST BE A LIST WITH ALL THE DATA WITH THE SAME TYPE
# IF YOU CREATE A LIST IN PYTHON WITH THE SAME DATA TYPE IN THE VARIABLES, ITS GONNA BE A ARRAY
# BUT IF YOU HAVE DIFFERENT DATA TYPES INSIDE OF A LIST IT ISN'T A ARRAY 
# BUT YOU CAN USE NUMPY.ARRAY TO ARRANGE ALL OF THEM TO BE THE SAME DATA TYPE
# STR > FLOAT > INT > BOOL

listas = [[82, 7, 10, 13, 22],
          [1.2, 8, 91, 10.72],
          [2, True, False, 9, 32, False],
          [9.4, True, False, 2],
          [3, "Hi", 2, "Lasanha"],
          ["Hello", 2, 8.91, False]]


while True:
    print("\n\n")
    print("Array and List Tester\n")
    a = int(input("List[0] | Array[1]: "))
    if a == 1:
        #ARRAYS NUMPY
        print("\n")
        for n in range(len(listas)):
            print("{} - ".format(n), np.array(listas[n]), "\n")
            
            try:
                print("max: ", np.max(np.array(listas[n])), "\n")
            
                print("min", np.min(np.array(listas[n])), "\n")
            
            except:
                print("Max and Min: can't be used in a array with string!\n")
           
            print("sort: ", np.sort(np.array(listas[n])), "\n") #Sort in crescent order
           
            print("flip: ", np.flip(np.array(listas[n])), "\n") #Flip the array, Last term = First term 
            
            try:
                print("mean: ", np.mean(np.array(listas[n])), "\n")
    
                print("median: ",np.median(np.array(listas[n])), "\n")
                
                print("std: ",np.std(np.array(listas[n])), "\n")
            except:                
                print("Mean, Median and STD: can't be executed in arrays with string")
    
    else:
        #LISTAS
        print("\n")
        for n in range(len(listas)):
            print("{} - ".format(n), listas[n], "\n")
            try:
                print("max: ",max(listas[n]), "\n") #Max
                
                print("min: ",min(listas[n]), "\n") #Min
            
            except:
                print("You cant use max or min in a array with string!\n")

            try:
                listas[n].sort() #Sort in Crescent Order
                
                print("sort: ",listas[n], "\n")

                listas[n].sort(reverse=True) #Sort in decrecent Order
                
                print("Sort(reverse=True): ",listas[n], "\n")
            
            
            except:
                print("You can't sort a list with STR and INT\n")

            listas[n].reverse() #Flip the list, Last term = First term

            print("Reverse: ", listas[n], "\n")

    
    

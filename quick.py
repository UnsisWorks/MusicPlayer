import msvcrt as m
from colorama import Cursor, init, Fore, Back, Style
import time
import os
# import msvcrt


def main():
    os.system('clear')
    # print("\033[1;34m") 
    print(Style.BRIGHT + "Intensidad alta")
    L1 = [ 8, 9, 7, 6, 10, 4, 0]
    L2 = [ 5 ]
    L3 = [ 1, 2, 4, 3 ]
    
    print(L1)
    quicksort(L1, 0, 6)
    print("")
    

def quicksort(L, first, last):
    # definimos los índices y calculamos el pivote
    i = first
    j = last    
    pivote = (L[i] + L[j]) / 2

    # iteramos hasta que i no sea menor que j
    while (i < j):
        # time.sleep(5)
        # input("")
        print(f"\rL: {L} firts: {first} last: {last}", end='')
        # iteramos mientras que el valor de L[i] sea menor que pivote
        while (L[i] < pivote):
            # Incrementamos el índice
            i+=1
        # iteramos mientras que el valor de L[j] sea mayor que pivote
        while (L[j] > pivote):
            # decrementamos el índice
            j-=1
        # si i es menor o igual que j significa que los índices se han cruzado
        if (i <= j):
            # creamos una variable temporal para guardar el valor de L[j]
            x = L[j]
            # intercambiamos los valores de L[j] y L[i]
            L[j] = L[i]
            L[i] = x
            # incrementamos y decrementamos i y j respectivamente
            i+=1
            j-=1

    # time.sleep(1)
    # si first es menor que j mantenemos la recursividad
    if (first < j):
        print(f"\rL: {L}", end='\r')
        L = quicksort(L, first, j)
    # si last es mayor que i mantenemos la recursividad
    if (last > i):
        print(f"\rL: {L}", end='')
        L = quicksort(L, i, last)

    # devolvemos la lista ordenada
    return L


if __name__ == '__main__':
    main()
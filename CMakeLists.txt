cmake_minimum_required(VERSION 4.2)
project(ED2 C)

set(CMAKE_C_STANDARD 11)

include_directories(zero)

cmake_minimum_required(VERSION 3.10)
project(ED2)

# Aula 09-04
add_executable(aula_0904
        "Aula - 09_04/main.c"
        "Aula - 09_04/BinTree.c"
)

# Aula 26-03
add_executable(aula_2603
        "Aula - 26_03/main.c"
        "Aula - 26_03/BinTree.c"

)

# Aula 28-03
add_executable(aula_2803
        "Aula - 28_03/main.c"
        "Aula - 28_03/BinTree.c"

)

# Exercicio 1
add_executable(Exercicio_1
        "Exercicio_1/main.c"
        "Exercicio_1/BinTree.c"
)

#Bintree
add_executable(zero
        "zero/main.c"
        "zero/Bintree.c"
)

#AVL
add_executable(AVLestudos
        "AVLestudos/main.c"
        "AVLestudos/AVLtree.c"
)

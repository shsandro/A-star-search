# A-star-search

## Contexto

Uma implementação básica do algoritmo de busca A\* é oferecida para resolução do jogo 15-puzzle, podendo ser utilizadas diferentes heurísticas, sendo elas: número de peças fora do lugar, número de peças fora de ordem, distância de Manhattan, combinação linear entre heurísticas e máximo valor entre heurísticas. Todos os módulos foram implementados em C++.

## Compilação

Para compilação do código execute `make` no diretório raiz. O execútavel `a-star` será gerado.

## Execução

São oferecidos dois parâmetros:

- `-h`: exibe ajuda
- `-i`: indica a heurística a ser utilizada

Execute `./a-star -i <heuristic name> [-h]` para rodar o algoritmo. As heurísticas padrões fornecidas são:

- out_of_place: number of pieces of out place compared to final configuration
- out_of_order: number of pieces out of order in the numerical sequence, following the order of positions on the board
- manhattan_distance: standart Manhattan Distance
- heuristic_4: linear combination of the three previous heuristics, where the sum of the coefficients must be equal one
- heuristic_5: max value between out_of_place, out_of_order and manhattan_distance

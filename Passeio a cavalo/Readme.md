# Problema do Passeio a Cavalo

## Sobre

O problema do passeio a cavalo é um problema clássico de backtracking. O objetivo é encontrar um caminho no qual um cavalo de xadrez visita cada quadrado de um tabuleiro exatamente uma vez. Este problema também é conhecido como o "problema do cavaleiro".

## Explicação

Para resolver este problema, usamos uma abordagem de backtracking onde o cavalo tenta se mover para cada uma das oito posições possíveis a partir da sua posição atual e, recursivamente, tenta completar o passeio.

## Abordagem de Solução

### Funcionamento da Abordagem

1. **Movimentos do Cavalo:**
   - O cavalo de xadrez pode se mover em um padrão de "L", que consiste em dois movimentos em uma direção e um movimento perpendicular, ou vice-versa. Existem 8 possíveis movimentos a partir de qualquer posição `(x, y)`.

2. **Backtracking:**
   - Começamos em uma posição inicial `(x, y)` e tentamos mover o cavalo para uma das 8 posições possíveis.
   - Se o movimento é válido (dentro dos limites do tabuleiro e não visitado antes), o cavalo se move para essa posição e marca como visitada.
   - A função é chamada recursivamente para a nova posição.
   - Se um movimento leva a uma solução completa (todos os quadrados são visitados), a solução é registrada.
   - Se um movimento não leva a uma solução, desfazemos o movimento (backtracking) e tentamos outro movimento.

### Algoritmo

1. **Inicialização:**
   - Crie uma matriz para representar o tabuleiro e marque todos os quadrados como não visitados.
   - Defina os possíveis movimentos do cavalo.

2. **Backtracking:**
   - Comece na posição inicial `(x, y)` e marque como visitada.
   - Tente mover o cavalo para cada uma das 8 posições possíveis.
   - Se um movimento é válido, mova o cavalo e marque a nova posição como visitada.
   - Chame a função recursivamente para a nova posição.
   - Se o movimento não leva a uma solução, desfaça o movimento (backtracking) e tente outro movimento.

3. **Condição de Parada:**
   - Se o número de movimentos realizados é igual ao número de quadrados no tabuleiro, a solução está completa.

### Exemplo

Para um tabuleiro de xadrez de 8x8, começando na posição `(0, 0)`, o algoritmo tenta todas as possíveis sequências de movimentos do cavalo até encontrar uma sequência que visite todos os 64 quadrados exatamente uma vez.

## Complexidade

### Complexidade de Tempo

A complexidade de tempo no pior caso é muito alta devido à natureza do problema de backtracking. Para um tabuleiro de `n x n`, o cavalo tem até 8 movimentos possíveis em cada posição, levando a uma complexidade de \(O(8^{n^2})\) no pior caso. No entanto, heurísticas como a Regra de Warnsdorff podem ser aplicadas para reduzir significativamente o tempo de execução na prática.

---

## Conclusão

O problema do passeio a cavalo é um problema clássico de backtracking que pode ser resolvido recursivamente tentando todos os possíveis movimentos do cavalo e usando a técnica de backtracking para desfazer movimentos que não levam a uma solução. Embora a complexidade de tempo no pior caso seja muito alta, heurísticas podem ser usadas para encontrar soluções mais rapidamente na prática. A complexidade de espaço é proporcional ao tamanho do tabuleiro, tornando o algoritmo eficiente em termos de memória.


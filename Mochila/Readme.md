# Problema da Mochila

## Sobre

O problema da mochila (knapsack problem) é um problema clássico de otimização combinatória. Dado um conjunto de itens, cada um com um peso e um valor, e uma capacidade máxima de peso que a mochila pode carregar, o objetivo é determinar a combinação de itens que maximiza o valor total sem exceder a capacidade de peso da mochila.

## Explicação

### Definição do Problema

Dado:
- Um conjunto de `n` itens, onde cada item `i` tem um valor `vi` e um peso `wi`.
- Uma capacidade máxima `W` que a mochila pode carregar.

O objetivo é encontrar um subconjunto de itens cuja soma dos pesos seja menor ou igual a `W` e cuja soma dos valores seja a maior possível.

### Abordagem de Solução

A abordagem clássica para resolver o problema da mochila é usar programação dinâmica. A ideia é construir uma tabela auxiliar que nos ajude a determinar a melhor combinação de itens.

Vamos chamar essa tabela auxiliar de `T`. Se temos `n` itens e uma capacidade `W`, `T[i][j]` representará o valor máximo que pode ser obtido com os primeiros `i` itens e uma capacidade de mochila `j`.

#### Construção da Tabela

1. **Inicialização:**
   - `T[0][j]` para `0 <= j <= W` é 0, pois com 0 itens, o valor máximo é 0.

2. **Preenchimento da Tabela:**
   - Para cada item `i` de 1 a `n` e cada capacidade `j` de 0 a `W`:
     - Se o peso do item `i` for maior que `j`, `T[i][j]` será igual a `T[i-1][j]` (não podemos incluir o item `i`).
     - Caso contrário, `T[i][j]` será o máximo entre `T[i-1][j]` (não incluir o item `i`) e `T[i-1][j - wi] + vi` (incluir o item `i`).

#### Algoritmo

1. Inicialize a tabela `T` com dimensões `(n+1) x (W+1)`.
2. Preencha a primeira linha conforme as condições de inicialização.
3. Preencha o restante da tabela usando a fórmula de transição.
4. O valor em `T[n][W]` representará o valor máximo que pode ser obtido com a capacidade total da mochila.

### Exemplo

Considere um conjunto de itens com valores e pesos `v = [60, 100, 120]` e `w = [10, 20, 30]`, e uma capacidade máxima da mochila `W = 50`.

A tabela `T` será construída conforme descrito e ao final, `T[3][50]` nos dará o valor máximo que pode ser carregado na mochila, que neste caso é 220.

## Complexidade

### Complexidade de Tempo

A complexidade de tempo do algoritmo clássico de programação dinâmica para o problema da mochila é `O(n x W)`, onde:
- `n` é o número de itens.
- `W` é a capacidade máxima da mochila.

Isso ocorre porque o algoritmo preenche uma tabela de tamanho `(n+1) x (W+1)`, e cada entrada da tabela leva tempo constante `O(1)` para ser calculada. Portanto, o tempo total é proporcional ao número de entradas na tabela.

### Complexidade de Espaço

A complexidade de espaço também é `O(n x W)` devido à necessidade de armazenar a tabela auxiliar de tamanho `(n+1) x (W+1)`.

No entanto, é possível otimizar a complexidade de espaço para `O(W)` usando apenas uma matriz de uma dimensão, já que para atualizar a linha `i` da tabela, só precisamos da linha `i-1`. Assim, podemos usar uma única matriz de tamanho `W+1` e atualizá-la iterativamente.

### Resumo da Complexidade

- **Complexidade de Tempo:** `O(n x W)`
- **Complexidade de Espaço:** `O(n x W)` (ou `O(W)` com otimização de espaço)

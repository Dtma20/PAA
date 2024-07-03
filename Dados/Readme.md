# Problema dos n Dados

## Sobre

O problema dos n dados envolve determinar se é possível obter uma soma específica k a partir dos lançamentos de n dados, onde cada dado pode mostrar qualquer número de 1 a 6.

## Explicação Matemática e Lógica

### Estrutura do Problema

Quando se lança um dado, ele pode resultar em qualquer número de 1 a 6. Se lançarmos n dados, cada dado contribui independentemente para a soma total. Nosso objetivo é encontrar se existe alguma combinação de resultados desses n dados que somam exatamente k.

### Abordagem de Solução

#### 1. Análise de Estados

Imagine que queremos encontrar todas as possíveis somas que podemos obter com n dados. Vamos definir um estado `dp[i][j]` que representa o número de maneiras de obter a soma j usando i dados.

#### 2. Condições Iniciais

- Com 0 dados, só é possível ter uma soma de 0, ou seja, `dp[0][0] = 1`.

#### 3. Transição de Estados

Para cada dado adicional, precisamos atualizar nossas possibilidades de soma. Se temos i dados e queremos calcular as somas possíveis ao adicionar um novo dado, podemos pensar da seguinte maneira:

- Para cada soma j que podemos obter com i dados, podemos obter a soma j + 1 ao adicionar uma face 1 no próximo dado, a soma j + 2 ao adicionar uma face 2, e assim por diante até a soma j + 6.

Matematicamente, a transição pode ser descrita como:

`dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + dp[i-1][j-3] + dp[i-1][j-4] + dp[i-1][j-5] + dp[i-1][j-6]`

Isso significa que o número de maneiras de obter a soma j com i dados é a soma das maneiras de obter a soma j-1, j-2, ..., j-6 com i-1 dados.

#### 4. Restrição de Somatório

Para i dados, a soma mínima é i (se todos os dados mostrarem 1) e a soma máxima é 6 * i (se todos os dados mostrarem 6). Portanto, só precisamos considerar somas j no intervalo [i, 6 * i].

#### 5. Verificação do Resultado

Após calcular as possibilidades de soma para todos os n dados, verificamos se k está no intervalo possível [n, 6 * n]. Se estiver, a quantidade `dp[n][k]` nos dirá o número de maneiras de obter a soma k. Se for maior que 0, então é possível obter a soma k com n dados.

### Exemplo

Para n = 2 e k = 7:

- Com o primeiro dado, podemos obter as somas 1, 2, 3, 4, 5, 6.
- Com o segundo dado, somamos cada uma das faces do primeiro dado com 1, 2, 3, 4, 5, e 6.

Portanto, as somas possíveis são:

```
1 + {1, 2, 3, 4, 5, 6}
2 + {1, 2, 3, 4, 5, 6}
...
6 + {1, 2, 3, 4, 5, 6}
```

- Isso resulta em possíveis somas de 2 a 12.
- A soma 7 pode ser obtida de várias maneiras: 1 + 6, 2 + 5, 3 + 4, 4 + 3, 5 + 2, 6 + 1.

### Complexidade

#### Complexidade de Tempo

A complexidade de tempo para calcular todas as possíveis somas é O(n * 6n) = O(n²). Isto porque precisamos considerar cada dado e cada soma possível.

#### Complexidade de Espaço

A complexidade de espaço é O(n * 6n) = O(n²), pois precisamos armazenar todas as possíveis somas para cada dado em uma matriz.

---

## Conclusão

O problema dos n dados pode ser resolvido utilizando uma abordagem de programação dinâmica para calcular o número de maneiras de obter uma soma específica k com n dados. Esta lógica matemática pode ser implementada em qualquer linguagem de programação, bastando seguir os princípios descritos acima.
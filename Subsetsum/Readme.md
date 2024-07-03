# Subconjunto de soma

## Sobre

O problema do subconjunto de soma é um problema clássico de programação dinâmica. Dado um conjunto de números inteiros e um valor alvo, o objetivo é determinar se existe um subconjunto do conjunto cuja soma é igual ao valor alvo.

## Explicação

Para resolver este problema, usamos uma abordagem de programação dinâmica onde construímos uma tabela auxiliar que nos ajuda a determinar se um subconjunto com a soma igual ao valor alvo existe.

Vamos chamar essa tabela auxiliar de `T`. Se temos um conjunto `S` com `n` elementos e um valor alvo `k`, `T[i][j]` será verdadeiro se for possível obter uma soma `j` usando os primeiros `i` elementos do conjunto `S`. Caso contrário, `T[i][j]` será falso.

## Construção da Tabela

1. **Inicialização:**
   - `T[0][0]` é verdadeiro, pois uma soma de `0` pode ser obtida com um subconjunto vazio.
   - Para todos os outros `j` onde `j > 0`, `T[0][j]` é falso, pois não podemos obter uma soma positiva sem elementos.

2. **Preenchimento da Tabela:**
   - Para cada elemento `i` de 1 a `n` e cada soma `j` de 0 a `k`, temos duas opções:
     - Excluir o `i`-ésimo elemento: Neste caso, `T[i][j]` será verdadeiro se `T[i-1][j]` for verdadeiro.
     - Incluir o `i`-ésimo elemento: Neste caso, `T[i][j]` será verdadeiro se `T[i-1][j - S[i-1]]` for verdadeiro e `j >= S[i-1]`.

A fórmula de transição é:
\[ T[i][j] = T[i-1][j] \text{ ou } (j \geq S[i-1] \text{ e } T[i-1][j - S[i-1]]) \]

## Algoritmo

1. Inicialize a tabela `T` com dimensões `(n+1) x (k+1)`.
2. Preencha a primeira linha conforme as condições de inicialização.
3. Preencha o restante da tabela usando a fórmula de transição.
4. O valor em `T[n][k]` indicará se é possível ou não obter a soma `k` usando os elementos do conjunto `S`.

## Complexidade

A complexidade de tempo do algoritmo é \(O(n \times k)\), onde:
- \(n\) é o número de elementos no conjunto \(S\).
- \(k\) é o valor alvo.

Isso ocorre porque o algoritmo preenche uma tabela de tamanho \((n+1) \times (k+1)\), e cada entrada da tabela leva tempo constante \(O(1)\) para ser calculada. Portanto, o tempo total é proporcional ao número de entradas na tabela.

## Exemplo

Considere o conjunto `S = {3, 34, 4, 12, 5, 2}` e o valor alvo `k = 9`.

A tabela `T` será construída conforme descrito e ao final, `T[6][9]` nos dirá se é possível formar a soma `9` usando os elementos do conjunto `S`.

## Conclusão

O problema do subconjunto de soma pode ser resolvido eficientemente usando programação dinâmica. A tabela auxiliar `T` ajuda a determinar se existe um subconjunto cuja soma é igual ao valor alvo. Se `T[n][k]` for verdadeiro, significa que tal subconjunto existe. Caso contrário, significa que não é possível encontrar um subconjunto com a soma igual ao valor alvo.
# Семинар №2 - Сложност на алгоритми - продължение
## Изчисляване на сложност
### Сложност на итеративни алгоритми
Итеративни алгоритми са тези, които използват в рамките на своето изпълнение така наречените конструкции за цикъл - for, while, do-while.

[ **EXTRA** ] Най-разпространеният и прост метод за изчисляване на сложността им е подходът със **суми по изпълнението на циклите**.

**Примери:**

```c++
void sumFirstFive(vector<int>& arr) 
{
    int sum = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum += arr[0];
    }
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(1)
</details>
<br/>

```c++
void sum(vector<int>& arr) 
{
    int sum = 0;
    size_t n = arr.size();
    for (int i = 0; i < n; i++) 
    {
        sum += arr[0];
    }
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(n)
</details>
<br/>

```c++
void sum(vector<int>& arr) 
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) 
    {
        sum += arr[0];
    }
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(n)
</details>
<br/>

```c++
bool isPrime(int n) 
{
    if(n <= 1)
    {
    	return false;
    }

    bool isPrime = true;
    for (int i = 2; i <= sqrt(n); i++)
    {
    	if (n % i == 0)
    	{
    		isPrime = false; 
    		break;
    	}
    }

    return isPrime;
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(log(n) * n^(1/2))

  (Функцията sqrt има сложност Theta(log(n)))
</details>
<br/>

```c++
bool isPrime(int n) 
{
    if(n <= 1)
    {
    	return false;
    }

    bool isPrime = true;
    double sqrtFromNumberToCheck = sqrt(n);
    for (int i = 2; i <= sqrtFromNumberToCheck; i++)
    {
    	if (n % i == 0)
    	{
    		isPrime = false; 
    		break;
    	}
    }

    return isPrime;
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(n^(1/2))
</details>
<br/>

```c++
void doStuff(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 1; i <= n; i *= 2) 
    {
        // Theta(1)
    }
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(log(n))
</details>
<br/>


```c++
void doStuff(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 1; i <= n; i++) 
    {
        for(int j = i; j <= n; j++)
        {
            // Theta(1)
        }
    }
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(n^2)
</details>
<br/>

```c++
void doStuff(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j+=i)
        {
            // Theta(1)
        }
    }
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(n*log(n))
</details>
<br/>

```c++
void doStuff(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 2; i <= n; i *= 2) 
    {
        for(int j = 1; j <= i; j++)
        {
            // Theta(1)
        }
    }
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(n)
</details>
<br/>

### Сложност на рекурсивни алгоритми
Рекурсивни алгоритми са тези, които в рамките на своето изпълнение извикват себе си директно или индиректно, като входните данни на всяко следващо извикване трябва да бъдат различни.

[ **EXTRA** ] Има множество подходи за пресмятане на сложността на рекурсивен алгоритъм. Някои от тях са:
* Анализ на дървото на изпълнение
* Индукция по размера на входа
* Чрез рекурентни уравнения
* Други...

**Примери:**
```c++
int sum(int n) 
{
    if (n <= 0)
    {
        return 0;
    }
    return 1 + sum(n - 1);
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(n)
</details>
<br/>

```c++
int divSum(int n) 
{
    if (n <= 0)
    {
        return 0;
    }
    return 1 + sum(n/2);
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(log(n))
</details>
<br/>

```c++
unsigned fibb(unsigned n) 
{
    if (n < 2)
    {
        return 1;
    }
    return fibb(n-1) + fibb(n-2);
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(1.618^n)
</details>
<br/>

```c++
int tree(int n) 
{
    if (n <= 0)
    {
        return 0;
    }
    return tree(n - 1)+ tree(n - 1);
}
```
<details>
  <summary>Отговор</summary>
  Сложност по време: Theta(2^n)
</details>
<br/>

## Решаване на общи задачи
[01. Encode Password](https://www.hackerrank.com/contests/practice-1-sda/challenges/encoding-password)

[02. Majority Element](https://leetcode.com/problems/majority-element/description/)

[03. Water Volumes](https://leetcode.com/problems/container-with-most-water/description/)

[04. Single Number](https://leetcode.com/problems/single-number/description/)

[05. First Missing Positive](https://leetcode.com/problems/first-missing-positive/description/)

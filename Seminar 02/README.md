# Семинар №2 - Сложност на алгоритми - продължение. Бавни сортиращи алгоритми.
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
  Сложност по време: O(1)
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
  Сложност по време: O(n)
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
  Сложност по време: O(n)
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
  Сложност по време: O(log(n) * n^(1/2))
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
  Сложност по време: O(n^(1/2))
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
  Сложност по време: O(log(n))
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
  Сложност по време: O(n^2)
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
  Сложност по време: O(n^2)
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
  Сложност по време: O(n*log(n))
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
  Сложност по време: O(n)
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
  Сложност по време: O(log(n))
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
  Сложност по време: O(1.618^n)
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
  Сложност по време: O(2^n)
</details>
<br/>

## Решаване на общи задачи

## Бавни сортирания
### Bubble Sort (Optimized)
От така наречените "бавни" сортировки, Bubble sort намира може би най-малко приложение в практиката. Нека разгледаме някои от неговите показатели:

Сложност в най-добрият случай: **Theta(n)**

Сложност в среден случай: **Theta(n^2)**

Сложност в най-лошият случай: **Theta(n^2)**

Стабилност: **Да**

Адаптивност: Зависи (в общия случай - **Не**)

### Selection Sort (Optimized)
Макар с висока сложност дори и в най-добрият случай, оптимизираната версия на Selection sort притежава една много важна характеристика - **прави минимален брой swap-ове**. Тази негова характеристика намира широко приложение за данни, при които операцията swap е тежка. 

Сложност в най-добрият случай: **Theta(n^2)**

Сложност в среден случай: **Theta(n^2)**

Сложност в най-лошият случай: **Theta(n^2)**

Стабилност: **Не**

Адаптивност: **Не**

### Insertion Sort
Въпреки че е с квадратична сложност, Insertion sort е много разпространен алгоритъм за сортиране поради свойството си "адаптивност". Сортиращ алгоритъм наричаме **адаптивен**, когато работи бързо за почти-сортирани данни. Точно поради това свое предимство, Insertion sort е част от default-ната имплементация на std::sort().

Сложност в най-добрият случай: **Theta(n)**

Сложност в среден случай: **Theta(n^2)**

Сложност в най-лошият случай: **Theta(n^2)**

Стабилност: **Да**

Адаптивност: **Да**

## Решаване на задачи за сортиране
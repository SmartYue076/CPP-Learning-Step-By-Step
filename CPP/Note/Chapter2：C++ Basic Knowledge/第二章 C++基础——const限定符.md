## 第二章 C++基础——const限定符

### const限定符

const对象一经创建后其值不能再改变，所以const对象必须初始化

```C++
const int i = 1;
```

默认情况下，const对象仅在文件内有效。若需在不同文件使用同一const对象，则const变量不管是声明还是定义都添加extern关键字，这样只需定义一次就可以了
```C++
extern const int bufSize;
```



### const的引用

用于声明引用的const都是底层const，引用本身已默认为顶层const（无法改变指向）

const型变量只能由const型引用（底层const）

不能把普通引用绑定到字面值上，需用底层const

非const型变量可以由const型引用，但不可通过引用修改被引用变量值

```C++
int i = 0;
const int &r = i;
r = 1; //invalid
```



### 指针和常量

若变量为const，则它的指针或引用必为const

要想存放常量对象的地址，只能使用指向常量的指针（底层const）

指向常量的指针（pointer to const）不能通过指针改变常量值 —— 底层const

```C++
int i = 0;
const int *p = &i; // eqal to (int const *p =&i;)
*p = 1; //invalid
```

常量指针（const pointer）必须初始化，而且初始化完成后，其指向的地址不能再改变 —— 顶层const

```C++
int i = 0;
int j = 0;
int *const p = &i;
p = &j;	//invalid
```

指向常量的常量指针（const pointer to const），包含上述两种特性

```C++
int i = 0;
const int *const p = &i;
```



类和const

函数后加const表示不修改任何成员变量（通过const *this实现 ）

如果类包含const变量，必须通过初始化列表初始化



### 顶层const和底层const

当执行对象的拷贝操作时，顶层const不受影响

底层const要求拷入和拷出的对象必须具有相同的底层const资格，或者两个对象能相互转换。非常量可以转化为常量（等号右侧表达式），反之不行

## GDB使用手册

编译时加上`-g`选项

| 命令名称    | 命令缩写  | 命令说明                                             |
| ----------- | --------- | ---------------------------------------------------- |
| run         | r         | 运行一个待调试的程序                                 |
| continue    | c         | 让暂停的程序继续运行                                 |
| next        | n         | 运行到下一行                                         |
| step        | s         | 单步执行，遇到函数会进入                             |
| until       | u         | 运行到指定行停下来                                   |
| finish      | fi        | 结束当前调用函数，回到上一层调用函数处               |
| return      | return    | 结束当前调用函数并返回指定值，到上一层函数调用处     |
| jump        | j         | 将当前程序执行流跳转到指定行或地址，不运行跳过的代码 |
| print       | p         | 打印变量或寄存器值                                   |
| backtrace   | bt        | 查看当前线程的调用堆栈                               |
| frame       | f         | 切换到当前调用线程的指定堆栈                         |
| thread      | thread    | 切换到指定线程                                       |
| break       | b         | 添加断点                                             |
| tbreak      | tb        | 添加临时断点                                         |
| delete      | d         | 删除断点                                             |
| enable      | enable    | 启用某个断点                                         |
| disable     | disable   | 禁用某个断点                                         |
| watch       | watch     | 监视某一个变量或内存地址的值是否发生变化             |
| list        | l         | 显示源码                                             |
| info        | i         | 查看断点 / 线程等信息                                |
| ptype       | ptype     | 查看变量类型                                         |
| disassemble | dis       | 查看汇编代码                                         |
| set args    | set args  | 设置程序启动命令行参数                               |
| show args   | show args | 查看设置的命令行参数                                 |
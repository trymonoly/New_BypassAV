# New_BypassAV
多种技术集成在一起乱拳打死老师傅

微步沙箱执行结果
![image](https://github.com/trymonoly/New_BypassAV/blob/main/QQ%E5%9B%BE%E7%89%8720241125232052.png)
![image](https://github.com/trymonoly/New_BypassAV/blob/main/QQ%E5%9B%BE%E7%89%8720241125232058.png)

微软直接生成对应的mmc.bin的shellcode放在二进制文件同级目录下，shellcode进行加密或编码，如图：
![image](https://github.com/trymonoly/New_BypassAV/blob/main/Snipaste_2024-11-25_23-27-21.png)

对于卡巴斯基CS的shellcode无法支持在内存中执行代码，但是loader可以上线卡巴，如果想执行需要自己编写shellcode：
![image](https://github.com/trymonoly/New_BypassAV/blob/main/Snipaste_2024-11-25_23-22-41.png)
![image](https://github.com/trymonoly/New_BypassAV/blob/main/Snipaste_2024-11-25_23-23-15.png)

使用的技术：
PEB获取ntdll和kernel32,使用Nt 的APC执行代码上线，文件分离shellcode，加入自签名和版本信息

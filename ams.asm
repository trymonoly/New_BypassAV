.code
Getnt_64 proc
    mov rax, gs:[60h]     
    mov rax, [rax+18h]    
    nop
    mov rax, [rax+30h]           
    nop
    mov rax, [rax+10h]      
    ret
Getnt_64 endp

GetKernel32_64 proc
    mov rax, gs:[60h]       
    mov rax, [rax+18h]     
    mov rax, [rax+30h]      
    mov rax, [rax]          
    mov rax, [rax]          
    mov rax, [rax+10h]      
    ret
GetKernel32_64 endp

end
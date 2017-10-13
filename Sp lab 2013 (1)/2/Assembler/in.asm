lda 4201
movb,a
lda 4200
mvic ,00
subb
jnc ahead
inrc
cma
adi 01
ahead sta 4202
mova,c
sta 4203
hlt

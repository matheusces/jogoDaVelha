def imprimir(matriz):
    for i in range(3):
        for j in range(3):
            print matriz[i][j],
        print
    return None

s = cont = k = 0
matriz=[]
for i in range(3):
    c=[]
    for j in range(3):
        c.append("-")
    matriz.append(c)
imprimir(matriz)
jogador1 = raw_input("Digite o nome do Jogador X: ")
jogador2 = raw_input("Digite o nome do Jogador O: ")
for j in range(9):
    if s==1:
        break
    if k==1:
        break
    for i in range(2):
        if i==0:
            x = int(raw_input("%s digite a linha: " %(jogador1)))
            y = int(raw_input("%s digite a coluna: " %(jogador1)))
        else:
            x = int(raw_input("%s digite a linha: " %(jogador2)))
            y = int(raw_input("%s digite a coluna: " %(jogador2)))
        while x<0 or x>2 or y<0 or y>2 or matriz[x][y]=="X" or matriz[x][y]=="O":
            print "Erro.. digite novamente"
            if i==0:
                x = int(raw_input("%s digite a linha: " %(jogador1)))
                y = int(raw_input("%s digite a coluna: " %(jogador1)))
            else:
                x = int(raw_input("%s digite a linha: " %(jogador2)))
                y = int(raw_input("%s digite a coluna: " %(jogador2)))
        if i==0:
            matriz[x][y]="X"
        else:
            matriz[x][y]="O"
        imprimir(matriz)    
        if matriz[0][0]=="X" and matriz[0][1]=="X" and matriz[0][2]=="X":
            print "%s ganhou!!!" %jogador1
            s+=1
            break
        elif matriz[0][0]=="O" and matriz[0][1]=="O" and matriz[0][2]=="O":
            print "%s ganhou!!!" %jogador2
            s+=1
            break
        elif matriz[1][0]=="X" and matriz[1][1]=="X" and matriz[1][2]=="X":
            print "%s ganhou!!!" %jogador1
            s+=1
            break
        elif matriz[1][0]=="O" and matriz[1][1]=="O" and matriz[1][2]=="O":
            print "%s ganhou!!!" %jogador2
            s+=1
            break
        elif matriz[2][0]=="X" and matriz[2][1]=="X" and matriz[2][2]=="X":
            print "%s ganho!!!" %jogador1
            s+=1
            break
        elif matriz[2][0]=="O" and matriz[2][1]=="O" and matriz[2][2]=="O":
            print "%s ganhou!!!" %jogador2
            s+=1
            break
        elif matriz[0][0]=="X" and matriz[1][0]=="X" and matriz[2][0]=="X":
            print "%s ganhou!!!" %jogador1
            s+=1
            break
        elif matriz[0][0]=="O" and matriz[1][0]=="O" and matriz[2][0]=="O":
            print "%s ganhou!!!" %jogador2
            s+=1
            break
        elif matriz[0][1]=="X" and matriz[1][1]=="X" and matriz[2][1]=="X":
            print "%s ganhou!!!" %jogador1
            s+=1
            break
        elif matriz[0][1]=="O" and matriz[1][1]=="O" and matriz[2][1]=="O":
            print "%s ganhou!!!" %jogador2
            break
            s+=1
        elif matriz[0][2]=="X" and matriz[1][2]=="X" and matriz[2][2]=="X":
            print "%s ganhou!!!" %jogador1
            s+=1
            break
        elif matriz[0][2]=="O" and matriz[1][2]=="O" and matriz[2][2]=="O":
            print "%s ganhou!!!" %jogador2
            s+=1
            break
        elif matriz[0][0]=="X" and matriz[1][1]=="X" and matriz[2][2]=="X":
            print "%s ganhou!!!" %jogador1
            s+=1
            break
        elif matriz[0][0]=="O" and matriz[1][1]=="O" and matriz[2][2]=="O":
            print "%s ganhou!!!" %jogador2
            s+=1
            break
        elif matriz[0][2]=="X" and matriz[1][1]=="X" and matriz[2][0]=="X":
            print "%s ganhou!!!" %jogador1
            s+=1
            break
        elif matriz[0][2]=="O" and matriz[1][1]=="O" and matriz[2][0]=="O":
            print "%s ganhou!!!" %jogador2
            s+=1
            break
        elif j==4:
            for r in range(3):
                for u in range(3):
                    if matriz[r][u]!="-":
                        cont+=1
            if cont==9 and s==0:
                print "Deu velha!!!"
                k+=1
                break

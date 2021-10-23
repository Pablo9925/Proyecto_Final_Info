#include "zombie.h"

zombie::zombie(float posmx, float posmy, int tam)
{
    x=posmx;
    y=posmy;
    size=tam/5;
    spriZombie[0]=":/zombie/Attack (1).png";
    spriZombie[1]=":/zombie/Attack (2).png";
    spriZombie[2]=":/zombie/Attack (3).png";
    spriZombie[3]=":/zombie/Attack (4).png";
    spriZombie[4]=":/zombie/Attack (5).png";
    spriZombie[5]=":/zombie/Attack (6).png";
    spriZombie[6]=":/zombie/Attack (7).png";
    spriZombie[7]=":/zombie/AttackL (1).png";
    spriZombie[8]=":/zombie/AttackL (2).png";
    spriZombie[9]=":/zombie/AttackL (3).png";
    spriZombie[10]=":/zombie/AttackL (4).png";
    spriZombie[11]=":/zombie/AttackL (5).png";
    spriZombie[12]=":/zombie/AttackL (6).png";
    spriZombie[13]=":/zombie/AttackL (7).png";
    spriZombie[14]=":/zombie/Dead (1).png";
    spriZombie[15]=":/zombie/Dead (2).png";
    spriZombie[16]=":/zombie/Dead (3).png";
    spriZombie[17]=":/zombie/Dead (4).png";
    spriZombie[18]=":/zombie/Dead (5).png";
    spriZombie[19]=":/zombie/Dead (6).png";
    spriZombie[20]=":/zombie/Dead (7).png";
    spriZombie[21]=":/zombie/Dead (8).png";
    spriZombie[22]=":/zombie/Dead (9).png";
    spriZombie[23]=":/zombie/Dead (10).png";
    spriZombie[24]=":/zombie/DeadL (1).png";
    spriZombie[25]=":/zombie/DeadL (2).png";
    spriZombie[26]=":/zombie/DeadL (3).png";
    spriZombie[27]=":/zombie/DeadL (4).png";
    spriZombie[28]=":/zombie/DeadL (5).png";
    spriZombie[29]=":/zombie/DeadL (6).png";
    spriZombie[30]=":/zombie/DeadL (7).png";
    spriZombie[31]=":/zombie/DeadL (8).png";
    spriZombie[32]=":/zombie/DeadL (9).png";
    spriZombie[33]=":/zombie/DeadL (10).png";
    spriZombie[34]=":/zombie/Walk (1).png";
    spriZombie[35]=":/zombie/Walk (2).png";
    spriZombie[36]=":/zombie/Walk (3).png";
    spriZombie[37]=":/zombie/Walk (4).png";
    spriZombie[38]=":/zombie/Walk (5).png";
    spriZombie[39]=":/zombie/Walk (6).png";
    spriZombie[40]=":/zombie/Walk (7).png";
    spriZombie[41]=":/zombie/Walk (8).png";
    spriZombie[42]=":/zombie/Walk (9).png";
    spriZombie[43]=":/zombie/Walk (10).png";
    spriZombie[44]=":/zombie/WalkL (1).png";
    spriZombie[45]=":/zombie/WalkL (2).png";
    spriZombie[46]=":/zombie/WalkL (3).png";
    spriZombie[47]=":/zombie/WalkL (4).png";
    spriZombie[48]=":/zombie/WalkL (5).png";
    spriZombie[49]=":/zombie/WalkL (6).png";
    spriZombie[50]=":/zombie/WalkL (7).png";
    spriZombie[51]=":/zombie/WalkL (8).png";
    spriZombie[52]=":/zombie/WalkL (9).png";
    spriZombie[53]=":/zombie/WalkL (10).png";
    setPixmap(QPixmap(spriZombie[44]).scaled(size*4/5,size));
    setPos(x,y);
}

void zombie::movimientoi()
{
    if(mov==true){
        if(contmov>43){
            contmov=34;
        }
        x-=5;
        setPixmap(QPixmap(spriZombie[contmov+10]).scaled(size*4/5,size));
        setPos(x,y);
        contmov++;
    }
}

void zombie::movimientod()
{
    if(mov==true){
        if(contmov>43){
            contmov=34;
        }
        x+=5;
        setPixmap(QPixmap(spriZombie[contmov]).scaled(size*4/5,size));
        setPos(x,y);
        contmov++;
    }
}

void zombie::ataque()
{

}

void zombie::morir()
{

}

bool zombie::getImpacto() const
{
    return impacto;
}

void zombie::setImpacto(bool value)
{
    impacto = value;
}

float zombie::getX() const
{
    return x;
}

void zombie::setX(float value)
{
    x = value;
}

bool zombie::getVivo() const
{
    return vivo;
}

void zombie::setVivo(bool value)
{
    vivo = value;
}

bool zombie::getDirec() const
{
    return direc;
}

void zombie::setDirec(bool value)
{
    direc = value;
}

bool zombie::getMov() const
{
    return mov;
}

void zombie::setMov(bool value)
{
    mov = value;
}

float zombie::getY() const
{
    return y;
}

void zombie::setY(float value)
{
    y = value;
}

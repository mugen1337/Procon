template<typename T>
struct Dice{
    //left, right, front, back, down, up
    T l,r,f,b,d,u;

    void RollF(){ // y-- (next, d <- f)
        int tmp=d; d=f; f=u; u=b; b=tmp;
    }

    void RollB(){ // y++ (next, d <- b)
        int tmp=d; d=b; b=u; u=f; f=tmp;
    }

    void RollL(){ // x-- (next, d <- l)
        int tmp=d; d=l; l=u; u=r; r=tmp;
    }

    void RollR(){ // x++ (next, d <- r)
        int tmp=d; d=r; r=u; u=l; l=tmp;
    }
};

template<typename T>
bool same_dice_same_state(Dice<T> a,Dice<T> b){
    return (a.b==b.b and a.f==b.f and a.l==b.l and a.r==b.r and a.u==b.u and a.d==b.d);
}

template<typename T>
bool same_dice(Dice<T> a,Dice<T> b){
    for(int i=0;i<4;i++){
        a.RollL();
        for(int j=0;j<4;j++){
            a.RollB();
            for(int k=0;k<4;k++){
                a.RollL();
                if(same_dice_same_state(a,b)) return true;
            }
        }
    }
    return false;
}
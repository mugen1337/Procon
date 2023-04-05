/*
verify : https://atcoder.jp/contests/arc039/submissions/26243031

T -> int or long long
(x, y) : current position

move(['L', 'R', 'U', 'D'])
    その方向に進み，まだ訪問していない地点に到達したら移動終了
*/
template<typename T>
struct DancingLinks{
public:
    T x,y;
    map<tuple<T,T,char>,T> mp;
    DancingLinks(T sx=0,T sy=0):x(sx),y(sy){
        update();
    }
    // R,L,U,D(r,l,u,d) = (x++,x--,y++,y--)
    void move(char dir){
        if(dir=='R' or dir=='r') x=mp[{x,y,'R'}];
        if(dir=='L' or dir=='l') x=mp[{x,y,'L'}];
        if(dir=='U' or dir=='u') y=mp[{x,y,'U'}];
        if(dir=='D' or dir=='d') y=mp[{x,y,'D'}];
        update();
    }

private:
    void update(){
        if(!mp.count({x,y,'R'})) mp[{x,y,'R'}]=x+1;
        if(!mp.count({x,y,'L'})) mp[{x,y,'L'}]=x-1;
        if(!mp.count({x,y,'U'})) mp[{x,y,'U'}]=y+1;
        if(!mp.count({x,y,'D'})) mp[{x,y,'D'}]=y-1;
 
        mp[{mp[{x,y,'R'}],y,'L'}]=mp[{x,y,'L'}];
        mp[{mp[{x,y,'L'}],y,'R'}]=mp[{x,y,'R'}];
        mp[{x,mp[{x,y,'U'}],'D'}]=mp[{x,y,'D'}];
        mp[{x,mp[{x,y,'D'}],'U'}]=mp[{x,y,'U'}];
    }
};
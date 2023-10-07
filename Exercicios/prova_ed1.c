int x, y;

void Q(int u, int v){
    u = 2*u;
    x = u+v;
    u = u-1;
}

int main(){
    x = 4;
    y = 2;
    Q(x,y);
    printf("%d %d", x, y);
}

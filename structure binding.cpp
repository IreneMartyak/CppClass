struct Data
{
    int value;
    char character;
};
const Data foo()
{
    return Data{99, 'd'};
}
int main() /*48 byte*/ 
{
    auto [x, y] = foo();
    
    
    return y;
}
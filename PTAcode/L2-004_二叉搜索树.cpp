// https://www.cnblogs.com/yinzm/p/5527669.html
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1000+10;

struct Node {
    int value;
    Node *lson, *rson;
    Node():lson(NULL),rson(NULL){}
}*root;

int n;
int s[maxn];
vector<int> ans;

//当kind为true，代表进行二叉搜索树的判断，当kind为false，代表进行二叉搜索树镜像判断
bool _test(bool kind, int L, int R) {
    if(L >= R)return true;
    int i;
    for(i = L+1; i <= R; i++) {
        if(kind) {
            if(s[L] <= s[i]) {
                break;
            }
        }else {
            if(s[L] > s[i]) {
                break;
            }
        }
    }
    bool flag = true;
    for(int j = i; j <= R; j++) {
        if(kind) {
            if(s[j] < s[L]){
                flag = false;
            }
        }else {
            if(s[j] >= s[L]) {
                flag = false;
            }
        }
    }
    if(flag) {
        return _test(kind, L+1, i-1) && _test(kind, i, R);
    }else {
        return false;
    }
}

Node* _build(bool kind, int L, int R) {
    if(L > R) return NULL;
    int i;
    for(i = L+1; i <= R; i++) {
        if(kind) {
            if(s[L] <= s[i]) {
                break;
            }
        }else {
            if(s[L] > s[i]) {
                break;
            }
        }
    }
    Node *p = new Node();
    p->value = s[L];
    p->lson = _build(kind, L+1, i-1);
    p->rson = _build(kind, i, R);
    return p;
}

void post_order(Node *p) {
    if(p != NULL) {
        post_order(p->lson);
        post_order(p->rson);
        ans.push_back(p->value);
    }
}

void out_put() {
    post_order(root);
    int len = ans.size();
    for(int i = 0; i < len; i++) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    int flag = 0;
    if(_test(true, 0, n-1)) {
        flag = 1;
        root = _build(true, 0, n-1);
    }else if(_test(false, 0, n-1)) {
        flag = 2;
        root = _build(false, 0, n-1);
    }
    if(flag != 0) {
        puts("YES");
        out_put();
    }else {
        puts("NO");
    }    
    return 0;
}
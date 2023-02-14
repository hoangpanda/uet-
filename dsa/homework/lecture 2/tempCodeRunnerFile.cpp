freopen("input.txt","r",stdin);
    int n; cin >> n;
    linked_list list;
    for(int i = 1; i <= n; ++i) {
        int num; cin >> num;
        cout << num << ' ';
        list.insert(num);
    }
    list.print_list();
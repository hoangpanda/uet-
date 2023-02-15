vector<int> num = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    for(auto v:num) cout << hash_f(v) << ' ';
    cout << endl;

    vector<link_list> a(10);
    for(auto v:num) {
        int hash_v = hash_f(v);
        a[i].insert(hash_v);
    }
    for(int i = 0; i < n; ++i) {
        if(!a[i].check_empty()) {
            a[i].print_list();
        }
    } 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Union-Find class
class UnionFind {
public:
    vector<int> parent;
    
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

// Function to merge accounts
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    UnionFind uf(n);
    unordered_map<string, int> emailToIndex; // Maps email to account index
    
    // Map each email to an account index using Union-Find
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            string email = accounts[i][j];
            if (emailToIndex.find(email) != emailToIndex.end()) {
                uf.unionSet(i, emailToIndex[email]);
            } else {
                emailToIndex[email] = i;
            }
        }
    }
    
    // Group emails by their root account index
    unordered_map<int, unordered_set<string>> indexToEmails;
    for (auto& [email, index] : emailToIndex) {
        int rootIndex = uf.find(index);
        indexToEmails[rootIndex].insert(email);
    }
    
    // Build the merged account list
    vector<vector<string>> mergedAccounts;
    for (auto& [index, emails] : indexToEmails) {
        vector<string> account(emails.begin(), emails.end());
        sort(account.begin(), account.end());
        account.insert(account.begin(), accounts[index][0]); // Add account name
        mergedAccounts.push_back(account);
    }
    
    return mergedAccounts;
}

int main() {
    // Input accounts
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };
    
    // Merge accounts
    vector<vector<string>> result = accountsMerge(accounts);
    
    // Output the result
    cout << "Merged Accounts:" << endl;
    for (const auto& account : result) {
        for (const string& s : account) {
            cout << s << " ";
        }
        cout << endl;
    }
    
    return 0;
}

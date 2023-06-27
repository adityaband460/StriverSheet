vector < vector < int >> findVertical(node * root) {
  // vertical num , level num , nodes at that pos in sorted order
  map < int, map < int, multiset < int >>> nodes;
  // that node , its vertical num, its level num
  queue < pair < node * , pair < int, int >>> todo;
  todo.push( {root,{0, 0}} ); //initial vertical and level
  while (!todo.empty()) {
    auto p = todo.front();
    todo.pop();
    node * temp = p.first;

    //x -> vertical , y->level
    int x = p.second.first, y = p.second.second;
    nodes[x][y].insert(temp -> data); //inserting to multiset

    if (temp -> left) {
      todo.push({
        temp -> left,
        {
          x - 1,  //reduce vertical by 1
          y + 1   // increase level by 1
        }
      });
    }
    if (temp -> right) {
      todo.push({
        temp -> right,
        {
          x + 1, //increase vertical by 1
          y + 1  // increase level by 1
        }
      });
    }
  }
  vector < vector < int >> ans;
  for (auto p: nodes) { // p :  ( vertical -> map(level,multiset) )
    vector < int > col;
    for (auto q: p.second) { // q : (level -> multiset)
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
}

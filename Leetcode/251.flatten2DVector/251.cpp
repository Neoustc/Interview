class Vector2D {
private:
	vector<int> data;
	int idx;
public:
    Vector2D(vector<vector<int>>& vec2d) {
      int row = vec2d.size();
      for (int r = 0; r < row; ++r)
      {
      	int col = vec2d[r].size();
      	for (int c = 0; c < col; c++)
      			data.push_back(vec2d[r][c]);

      }
      // for (auto& x : vec2d)
      // 	data.insert(data.end(), x.begin(), x.end());
      idx = 0;
    }

    int next() {
    	return data[idx++];
    }

    bool hasNext() {
    	return idx < data.size();
    }
};

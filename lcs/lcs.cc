#include <iostream>
#include <vector>

using namespace std;

// http://www.sourcetricks.com/2012/07/longest-common-substring-problem.html#.WUPNsROGOCQ
// http://www.talkativeman.com/longest-common-substring-algorithm/
// http://wiki.jikexueyuan.com/project/visual-studio/14.html
// https://stackoverflow.com/questions/15999272/how-to-convert-an-ascii-char-to-its-ascii-int-value
// https://stackoverflow.com/questions/4690415/negative-ascii-value
// http://www.learncpp.com/cpp-tutorial/27-chars/
// https://stackoverflow.com/questions/13412206/scanning-ascii-value-of-each-character-of-a-string

void CharSegment(const std::string &query, std::vector<std::string> &terms)  {
  terms.clear();
  for (size_t i = 0; i < query.size();) {
    if ((query[i] & 0xFC) == 0xFC && i+6<=query.size()) {
      terms.push_back(query.substr(i, 6));
      i += 6;
      continue;
    }
    if ((query[i] & 0xF8) == 0xF8 && i+5<=query.size()) {
      terms.push_back(query.substr(i, 5));
      i += 5;
      continue;
    }
    if ((query[i] & 0xF0) == 0xF0 && i+4<=query.size()) {
      terms.push_back(query.substr(i, 4));
      i += 4;
      continue;
    }
    if ((query[i] & 0xE0) == 0xE0 && i+3<=query.size()) {
      terms.push_back(query.substr(i, 3));
      i += 3;
      continue;
    }
    if ((query[i] & 0xC0) == 0xC0 && i+2<=query.size()) {
      terms.push_back(query.substr(i, 2));
      i += 2;
      continue;
    }
    terms.push_back(query.substr(i, 1));
    i += 1;
  }
}

std::string packStringFromVector(const std::vector<string> v, const int from, const int end){
  std::string result;
  vector<string>::const_iterator it_from = v.begin() + from;
  vector<string>::const_iterator it_end = v.begin() + end;

  for(vector<string>::const_iterator i =it_from; i != it_end; i++ ){
    result += *i;
  }

  return result;
}

bool longestCommonSubstring(const string& str1, const string& str2, string& result)
{
  bool rc = false;

  if(str1.empty() || str2.empty())
  {
    return false;
  }

  std::vector<string> str1v;
  std::vector<string> str2v;

  CharSegment(str1, str1v);
  CharSegment(str2, str2v);

  int *curr = new int [str2v.size()];
  int *prev = new int [str2v.size()];
  int *swap = NULL;
  int maxSubstr = 0;
   string longest;
  for(unsigned int i = 0; i < str1v.size(); ++i)
  {
    for(unsigned int j = 0; j < str2v.size(); ++j)
    {
      if(str1v[i] != str2v[j])
      {
        curr[j] = 0;
      }
      else
      {
        if(i == 0 || j == 0)
        {
          curr[j] = 1;
        }
        else
        {
          curr[j] = 1 + prev[j-1];
        }
        if(maxSubstr < curr[j])
        {
          maxSubstr = curr[j];
          longest.clear();
        }
        if (maxSubstr == curr[j])
        {
          longest += packStringFromVector(str1v, i - maxSubstr + 1, i + 1);
        }
      }
    }
    swap=curr;
    curr=prev;
    prev=swap;
  }

  delete [] curr;
  delete [] prev;
  
  if(longest.empty()){
    rc = false;
  } else {
    std::vector<string> longestVec;
    CharSegment(longest, longestVec);
    longest = packStringFromVector(longestVec, 0, maxSubstr);
    rc = true;
    result = longest;
  }

  return rc;
}


void testLsc(const std::string& input1, const std::string& input2){
    // std::string input1 = "foo";
    // std::string input2 = "bar";
    std::cout << "---- strings ---" << endl;
    std::cout << "input1:" << input1 << " length:" << input1.size() << endl;
    std::cout << "input2:" << input2 << " length:" << input2.size() << endl;
    std::string result;
    std::cout << "---- result ----" << endl;
    if(longestCommonSubstring(input1, input2, result)){
      std::cout << "longest common string: " << result << endl;
      std::cout << "length:" << result.size() << endl;
    } else {
      std::cout << "can not find longest common string." << endl;
      std::cout << "result:" << result << endl;
    }
}

int main() {
    // ---- lcs ----
    std::string input1 = "广发证券 广发";
    std::string input2 = "广发官微怎么设置消息自动推送 广发";
    testLsc(input1, input2);

    input1 = "日本政府";
    input2 = "北京中国北京";
    testLsc(input1, input2);

    input1 = "哈尔滨哈尔滨";
    input2 = "哈尔滨中国哈尔滨";
    testLsc(input1, input2);

    input1 = "北京四中";
    input2 = "中国北京";
    testLsc(input1, input2);

    input1 = "人民的名义";
    input2 = "的 名义";
    testLsc(input1, input2);
    // ---- packed string ----
    // std::string input1 = "中国";
    // std::vector<string> vec;
    // CharSegment(input1, vec);
    // std::cout << packStringFromVector(vec, 0, 2) << std::endl;;
}
class Solution {
private:
    std::vector<std::string> merge(std::vector<std::vector<std::string>>& solutions) {
        std::vector<std::string> answer;
        for (auto const& entry : solutions) {
            std::string merged;
            for (auto const& s : entry) merged.append(s + ".");
            merged.pop_back();
            answer.push_back(merged);
        }
        return answer;
    }
    bool isValid(std::string& segment) {
        if (segment.length() > 3) return false;
        if (segment.length() > 1 && segment.front() == '0') return false;
        return stoi(segment) <= 255;
    }
    void backtrack(
        std::vector<std::vector<std::string>>& solutions, 
        std::vector<std::string>& solution,
        std::string& source,
        int start) {
        if (start == source.length() && solution.size() == 4) {
            solutions.push_back(solution);
            return;
        }
        for (int i = start; i < source.length(); i++) {
            std::string segment = source.substr(start, i - start + 1);
            if (isValid(segment)) {
                solution.push_back(segment);
                backtrack(solutions, solution, source, i + 1);
                solution.pop_back();
            }
        }
    }
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        if (s.length() > 12) return {};
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> solution;
        backtrack(solutions, solution, s, 0);
        std::vector<std::string> answer = std::move(merge(solutions));
        return answer;
    }
};
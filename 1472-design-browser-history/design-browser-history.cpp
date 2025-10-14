class BrowserHistory {
private:
    vector<string> history;  // Store all URLs in history
    int current;            // Current position in history
    int end;               // Last valid position in history

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        current = 0;
        end = 0;
    }
    
    void visit(string url) {
        // Clear forward history by updating end
        current++;
        end = current;
        
        // Add new URL
        if (current >= history.size()) {
            history.push_back(url);
        } else {
            history[current] = url;
        }
    }
    
    string back(int steps) {
        // Move back at most 'steps' times
        current = max(0, current - steps);
        return history[current];
    }
    
    string forward(int steps) {
        // Move forward at most 'steps' times or until end
        current = min(end, current + steps);
        return history[current];
    }
};

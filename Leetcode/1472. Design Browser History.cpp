class BrowserHistory {
    vector<string> visitedURLs;
    int currURL, lastURL;
public:
    BrowserHistory(string homepage) {
        visitedURLs.push_back(homepage);
        currURL = 0; 
        lastURL = 0;
    }
    
    void visit(string url) {
        currURL += 1;
        if (visitedURLs.size() > currURL) {
            visitedURLs[currURL] = url;
        } else {
            visitedURLs.push_back(url);
        }
        lastURL = currURL;
    }
    
    string back(int steps) {
        currURL = max(0, currURL - steps);
        return visitedURLs[currURL];
    }
    
    string forward(int steps) {
        currURL = min(lastURL, currURL + steps);
        return visitedURLs[currURL];
    }
};

#include <iostream>
#include <string>
#include <map>

class TestProblem
{
private:
    std::map<std::string, int> subScore;
    int problemScore;
    static int totalScore;

public:
    TestProblem(void);
    TestProblem(const TestProblem& testProblem);
    ~TestProblem();
    void setSubScore(std::string key, int score);
    int getProblemScore(void);
    void show(void);
    static void showTotalScore(void);
};

int TestProblem::totalScore = 0;

TestProblem::TestProblem(void)
: problemScore(0) { }
TestProblem::TestProblem(const TestProblem& testProblem)
: subScore(testProblem.subScore), problemScore(testProblem.problemScore)
{
    this->totalScore += this->problemScore;
}

TestProblem::~TestProblem()
{
    this->totalScore -= this->problemScore;
}

void TestProblem::setSubScore(std::string key, int score)
{
    if(this->subScore.find(key) == this->subScore.end())
    {
        this->subScore[key] = score;
        this->problemScore += score;
        this->totalScore += score;
    }
    else
    {
        this->problemScore += score - subScore[key];
        this->totalScore += score - subScore[key];
        this->subScore[key] = score;
    }
}

int TestProblem::getProblemScore(void)
{
    return this->problemScore;
}

void TestProblem::show(void)
{
    for(std::map<std::string, int>::iterator it = this->subScore.begin(); it != this->subScore.end(); it++)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

void TestProblem::showTotalScore(void)
{
    std::cout << "total score : " << totalScore << std::endl;
}

int main(void)
{
    TestProblem problem1;
    TestProblem problem2 = problem1;

    problem1.setSubScore("subScore1", 30);
    problem1.setSubScore("subScore2", 40);
    problem2.setSubScore("subScore1", 20);
    problem2.setSubScore("subScore2", 40);

    problem1.show();
    std::cout << "problem1 score : " << problem1.getProblemScore() << std::endl; 
    problem2.show();
    std::cout << "problem2 score : " << problem2.getProblemScore() << std::endl;

    TestProblem::showTotalScore();
    
    return 0;
}
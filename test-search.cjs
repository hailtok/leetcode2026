const fs = require('fs');

async function testFetch() {
  const query = `query problemsetQuestionList($filters: QuestionListFilterInput) {
    problemsetQuestionList: questionList(categorySlug: "", limit: 5, skip: 0, filters: $filters) {
      total: totalNum
      questions: data {
        questionFrontendId
        titleSlug
        title
        difficulty
      }
    }
  }`;

  const res = await fetch("https://leetcode.com/graphql", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({
      query,
      variables: { filters: { searchKeywords: "01 Matrix" } }
    })
  });
  const data = await res.json();
  console.log(data.data.problemsetQuestionList.questions);
}
testFetch();


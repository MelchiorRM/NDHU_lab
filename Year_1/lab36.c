#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sid;
    int student_id;
    int course_id;
} Course;

typedef struct {
    int sid;
    int score;
} Score;

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    Course courses[m];
    Score scores[n];

    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &courses[i].sid, &courses[i].student_id, &courses[i].course_id);
    }

   
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &scores[i].sid, &scores[i].score);
    }

    int *student_map = calloc(m, sizeof(int));
    int *seen_students = calloc(m, sizeof(int));  
    int total_students = 0, failed_students = 0;

   
    for (int i = 0; i < m; i++) {
        int sid = courses[i].sid;
        int student_id = courses[i].student_id;

        
        if (!seen_students[student_id % m]) {
            seen_students[student_id % m] = 1;
            total_students++;
        }

        
        int total_score = 0, count = 0;
        for (int j = 0; j < n; j++) {
            if (scores[j].sid == sid) {
                total_score += scores[j].score;
                count++;
            }
        }

        
      if (count > 0 && total_score / count < 60) {
            student_map[student_id % m] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        if (student_map[i]) {
            failed_students++;
        }
    }

    printf("%d %d\n", total_students, failed_students);

    free(student_map);
    free(seen_students);

    return 0;
}

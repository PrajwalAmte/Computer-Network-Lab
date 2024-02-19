#include <stdio.h>
#include<stdlib.h>

void GoBackN(int totalFrame, int windowSize) {
    int currentFrame = 1;

    while (currentFrame <= totalFrame) {
        for (int i = currentFrame; i < currentFrame + windowSize && i <= totalFrame; i++) {
            printf("Sending Frame %d\n", i);
        }

        for(int j = 0; j < windowSize && currentFrame <= totalFrame; j++) {
            int random = rand();
            if (random % 2) {
                printf("Acknowledgment Received for frame %d\n", currentFrame);
                currentFrame++;
            } else {
                printf("Acknowledgement not received for frame %d\n", currentFrame);
                break;
            }
        }
        printf("Retransmitting window\n");
    }
}

void selectiveRepeat(int totalFrame, int windowSize) {
    int currentFrame = 1;

    while (currentFrame <= totalFrame) {
        for(int i = currentFrame; i < currentFrame + windowSize && i <= totalFrame; i++) {
            printf("Sending Frame %d\n", i);
        }

        for(int j = 0; j < windowSize && currentFrame <= totalFrame; j++) {
            int random = rand();
            if (random % 2) {
                printf("Ackowledgement Received from frame %d\n", currentFrame);
                currentFrame++;
            } else {
                printf("Ackowledgement not Received for frame %d\n", currentFrame);
                printf("Resending frame %d\n", currentFrame);
                printf("Ackowledgement Received for frame %d\n", currentFrame);
                currentFrame++;
            }
        } 
        printf("Retransmitting window\n");
    }
}

int main() {
    int frames, windowSize;
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter window size: ");
    scanf("%d", &windowSize);
    
    printf("\nGo-Back-N ARQ:\n");
    GoBackN(frames, windowSize);
    
    printf("\nSelective Repeat:\n");
    selectiveRepeat(frames, windowSize);
    
    return 0;
}
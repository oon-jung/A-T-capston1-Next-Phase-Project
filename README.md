# Next Phase Project

중앙대학교 예술공학부  
**2025 캡스톤 디자인 프로젝트 I (1분반)**


## **Team Members**
- **김운정 (Team Leader)**  
  AI 이미지·비디오 생성, 영상 편집, CLO 3D 기반 디지털 패션, 웹 개발, AI 음악 생성

- **박영준**  
  게임 엔진 기반 인터랙션 개발, 3D 프린팅, 무대 디자인, 애니메이션, 디지털 의상 파이프라인 구축

- **서은현**  
  3D 모델링, 리깅(Rigging), 애니메이션, 디지털 의상 파이프라인 구축

- **이지수**  
  AI 이미지·비디오 생성, 영상 편집, 캐릭터 콘셉트 아트, 3D 모델링, 텍스처링

---

## **Project Overview**
**Music Video (YouTube)**  
https://www.youtube.com/watch?v=0jMcE6W8ViQ

**Next Phase Project**는 기존의 일방향적인 뮤직비디오 감상 방식에서 벗어나,  
관객의 행동이 공연 연출에 직접적으로 반영되는 **인터랙티브 뮤직비디오 전시 콘텐츠**를 목표로 한 프로젝트이다.

기존 뮤직비디오는 완성된 영상을 감상하는 형식에 머물러 있었으나,  
본 프로젝트는 영상과 전시 공간을 결합하여 관객이 공연의 일부로 참여하는 구조를 제안한다.  
관객은 **응원봉을 활용한 인터랙션**을 통해 무대 연출과 분위기에 영향을 주며,  
이를 통해 작품은 관객의 참여로 완성되는 **경험형 콘텐츠**로 확장된다.

본 오버뷰 상단에 포함된 뮤직비디오는 프로젝트의 **세계관**, **시각적 콘셉트**,  
그리고 **2D 영상에서 3D 인터랙션 무대로 이어지는 전체 흐름**을 가장 직접적으로 보여준다.

---

## **Background and Objective**
본 프로젝트는 현대 사회에서 개인이 **수치와 데이터로 평가·관리되는 구조**에 주목하였다.  
이러한 구조를 아이돌 연습생의 서사로 치환하여, **퍼센트, 게이지, 스캔 프레임** 등  
평가 시스템 UI를 주요 시각 언어로 활용하였다.

작품은 **2D 뮤직비디오에서 시작해 3D 무대로 전환되는 단계적 구조**를 취하며,  
평가 시스템 안에 있던 인물들이 관객과 함께 무대를 완성해 나가는 과정을 중심 서사로 삼는다.  
이를 통해 관객은 단순한 감상자가 아닌, **공연에 개입하는 참여자**로서의 경험을 하게 된다.

---

## **Core Concept**
- 평가 시스템에 의해 규정된 존재의 서사
- 퍼센트, 게이지, 프레임 기반 UI를 활용한 시각적 표현
- **2D 데이터 세계에서 3D 현실 무대로의 전환**
- 관객 인터랙션을 통해 완성되는 무대 연출

---

## **Interaction Features**
- **Shake to Play**  
  관객이 응원봉을 흔들면 뮤직비디오 및 무대가 재생되는 인터랙션 기능

- **Confetti Interaction**  
  응원봉의 흔들림 강도에 따라 3D 무대에서 발생하는 컨페티 효과의 양과 강도가 변화

- **Audience Synchronization**  
  관객의 응원봉 움직임이 3D 씬 속 관객 응원봉과 동기화되어 함께 반응

---

## **Technical Stack**
- **Game Engine**: Unreal Engine
- **3D Modeling / Rigging**: Maya
- **Texturing**: Substance Painter
- **Digital Fashion**: CLO 3D
- **Hardware**: ESP32, MPU6050 (Gyro / Accelerometer)
- **Communication**: OSC (Open Sound Control)
- **AI Tools**: Midjourney, Veo 3.1, Grok, Suno AI
- **Web**: TypeScript 기반 웹 페이지

---

## **Repository Structure**
- **OSC_Controller/** : 응원봉 센서 제어 및 OSC 통신 코드
- **web/** : 프로젝트 소개 웹 페이지
- **3d_models/** : 3D 모델 및 에셋
- **NPP_Unreal_Package.exe** : 언리얼 엔진 패키징 실행 파일

---

## **Course Information**
- **Course**: Capstone Design Project I  
- **Department**: College of Arts & Technology  
- **Professor**: 옥창엽  
- **Year**: 2025



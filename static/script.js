// script.js

document.addEventListener('DOMContentLoaded', () => {
    const hamburger = document.querySelector('.hamburger');
    const navMenu = document.querySelector('nav ul');
    const headerTitle = document.querySelector('header h1 button');

    const smoothScrollTo = (targetElement) => {
        if (targetElement) {
            const offsetTop = targetElement.getBoundingClientRect().top + window.scrollY;
            window.scrollTo({
                to: offsetTop,
                behavior: 'smooth'
            });
        }
    };


    headerTitle.addEventListener('click', (event) => {
        const mainSection = document.getElementById('main');
        smoothScrollTo(mainSection);
    });


    // 햄버거 버튼 클릭 시 메뉴 열기/닫기
    hamburger.addEventListener('click', () => {
        navMenu.classList.toggle('active');
    });



    // 메뉴 항목 클릭 시 메뉴 닫기
    navMenu.querySelectorAll('li a').forEach(item => {
        item.addEventListener('click', (event) => {
            const targetId = item.getAttribute('href');  //이동할 섹션의 ID 가져오기
            if (targetId && targetId.startsWith('#')){
                event.preventDefault();

                if (window.innerWidth <= 768) {
                    navMenu.classList.remove('active');
                }

                const targetElement = document.querySelector(targetId);  // 섹션 요소 가져오기
                smoothScrollTo(targetElement);
            }
        });
    });

    
    // 브라우저 크기 조절 시 메뉴 상태 조정
    window.addEventListener('resize', () => {
        if (window.innerWidth > 768) {
            navMenu.classList.remove('active');
        }
    });
});

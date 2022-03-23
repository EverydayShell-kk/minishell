//# include "../proto.h"
/*
기능

EOF 까지 입력을 받아 저장 후 stdin 으로 전달
	입력된 문자열과 EOF 비교 : 완벽하게 일치해야 함(뒤에 공백 x)
	받는 쪽에서 gnl() 처럼 읽기
다른 히어독과 차례로 stdin(keyboard) 를 점유해야 함.

테스트 케이스
cat << EOF > a.txt | cat << EDF > b.txt | cat << EFF > c.txt

가설
1. 부모쪽에서 히어독용 파이프 준비 후 자식들이 공유
	* 첫째 자식이 EOF 를 만나서 파이프를 닫는다고 해도 다음 자식이 fd 를 들고 있을텐데 닫히나?
2. 자식들이 각자 히어독용 파이프 생성 및 사용
3. 방법은 모르겠지만 부모쪽에서 히어독 처리 후 자식 실행
*/
/*
int	heredoc(char *EOF)
{
	int		fd;
	int		cmp_result;
	char	*buf;
	char	*save_dir = "temp.txt";

	cmp_result = -1;
	buf = 0;
	fd = open(save_dir, O_RDWR|O_APPEND|O_CREAT, 0755);
	while (cmp_result != 0)
	{
		buf = readline("heredoc>");
		cmp_result = ft_strncmp(buf, EOF, ft_strlen(EOF));
		if (buf)
		{
			write(fd, buf, ft_strlen(buf));
			write(fd, "\n", 1);
		}
	}
	dup2(fd, STDIN_FILENO);
	return (EXIT(SUCCESS));
}
*/
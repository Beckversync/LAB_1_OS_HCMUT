CC = gcc
CFLAGS = -Wall -g
TARGET = calc
SRCS = calc.c calc_logic.c
OBJS = $(SRCS:.c=.o)

# Mục tiêu mặc định
all: $(TARGET)

# Tạo tệp thực thi từ các tệp đối tượng
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Biên dịch từng tệp nguồn .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Lệnh làm sạch
clean:
	rm -f $(TARGET) $(OBJS)

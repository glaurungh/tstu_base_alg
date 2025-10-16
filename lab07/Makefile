.PHONY:
.SILENT:

# Цель по умолчанию
.DEFAULT_GOAL := help

build: ## Компиляция
	mkdir -p .bin && gcc -o ./.bin/main main.c -lm

run: build  ## Запуск
	./.bin/main

clean: ## Очистка
	rm -rf *.o && rm ./.bin/main

help:  ## Отображает список доступных команд
	@echo "Доступные команды:"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "  \033[36m%-30s\033[0m %s\n", $$1, $$2}'


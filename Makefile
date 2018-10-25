.PHONY: clean All

All:
	@echo "----------Building project:[ example - Debug ]----------"
	@cd "example" && "$(MAKE)" -f  "example.mk"
clean:
	@echo "----------Cleaning project:[ example - Debug ]----------"
	@cd "example" && "$(MAKE)" -f  "example.mk" clean

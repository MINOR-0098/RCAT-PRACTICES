PASSWORD = secret

.PHONY: Pass

secure_action:
	@read -p "Enter password: " input_password; \
	if [ "$$input_password" = "$(PASSWORD)" ]; then \
		echo "Password correct!"; \
                echo "Executing secure commands..."; \
	else \
		echo "Incorrect password!"; \
		exit 1; \
	fi

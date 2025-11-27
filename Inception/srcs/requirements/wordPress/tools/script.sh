#!/bin/sh

while ! mysqladmin ping -h"$DB_HOST" --silent; do
    echo "waiting for mysql ..."
    sleep 2
done

cd /var/www/html

wp core download --allow-root

wp config create --allow-root \
    --dbname="$DB_NAME" \
    --dbuser="$DB_USER" \
    --dbpass="$DB_PASSWORD" \
    --dbhost="$DB_HOST" \
    --dbcharset="utf8"

# -------------------- redis -------------------- #

wp config set WP_REDIS_HOST redis --allow-root
wp config set WP_REDIS_PORT 6379 --allow-root
wp config set WP_CACHE true --allow-root

# ------------------------------------------------ #

wp core install --allow-root \
    --url="$WP_URL" \
    --title="Inception" \
    --admin_user="$DB_USER" \
    --admin_password="$DB_PASSWORD" \
    --admin_email="mkartit9@gmail.com"

# -------------------- Theme & Content Setup -------------------- #

# Install and activate a modern theme (e.g., Twenty Twenty-Four)
wp theme install twentytwentyfour --activate --allow-root

# Create a sample page
wp post create --post_type=page --post_title='Welcome' --post_status=publish --allow-root \
    --post_content='<h1>Welcome to Inception Project</h1>
<p>This is a Docker-based WordPress installation with NGINX, MariaDB, and Redis cache.</p>
<h2>Features:</h2>
<ul>
<li>HTTPS with SSL</li>
<li>Redis Object Cache</li>
<li>MariaDB Database</li>
<li>PHP-FPM</li>
</ul>'

# Set the homepage to display the page we just created
wp option update show_on_front page --allow-root
wp option update page_on_front $(wp post list --post_type=page --post_title='Welcome' --field=ID --allow-root) --allow-root

# Customize site tagline
wp option update blogdescription "A Docker Infrastructure Project" --allow-root

# ---------------------------------------------------------------- #

wp plugin install redis-cache --activate --allow-root
wp redis enable --allow-root

chown -R www-data:www-data /var/www/html

echo "Starting PHP-FPM..."
exec $(find /usr/sbin -name 'php-fpm*' | sort -V | tail -n 1) -F
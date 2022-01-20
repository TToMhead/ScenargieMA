/ /   C o p y r i g h t   ( c )   2 0 0 7 - 2 0 1 7   b y   S p a c e - T i m e   E n g i n e e r i n g ,   L L C   ( " S T E " ) . 
 / /   A l l   R i g h t s   R e s e r v e d . 
 / / 
 / /   T h i s   s o u r c e   c o d e   i s   a   p a r t   o f   S c e n a r g i e   S o f t w a r e   ( " S o f t w a r e " )   a n d   i s 
 / /   s u b j e c t   t o   S T E   S o f t w a r e   L i c e n s e   A g r e e m e n t .   T h e   i n f o r m a t i o n   c o n t a i n e d 
 / /   h e r e i n   i s   c o n s i d e r e d   a   t r a d e   s e c r e t   o f   S T E ,   a n d   m a y   n o t   b e   u s e d   a s 
 / /   t h e   b a s i s   f o r   a n y   o t h e r   s o f t w a r e ,   h a r d w a r e ,   p r o d u c t   o r   s e r v i c e . 
 / / 
 / /   R e f e r   t o   l i c e n s e . t x t   f o r   m o r e   s p e c i f i c   d i r e c t i v e s . 
 
 # i f n d e f   M U L T I A G E N T _ A G E N T S I M _ H 
 # d e f i n e   M U L T I A G E N T _ A G E N T S I M _ H 
 
 # i n c l u d e   " m u l t i a g e n t _ c o m m o n . h " 
 # i n c l u d e   " m u l t i a g e n t _ s u p p o r t . h " 
 # i n c l u d e   " s c e n s i m _ n e t s i m . h " 
 # i n c l u d e   < d e q u e > 
 
 n a m e s p a c e   M u l t i A g e n t   { 
 
 u s i n g   S c e n S i m : : N e t w o r k S i m u l a t o r ; 
 u s i n g   S c e n S i m : : S i m u l a t i o n E v e n t ; 
 u s i n g   S c e n S i m : : S h a p e S e n s i n g M o d e l ; 
 u s i n g   S c e n S i m : : F a n S e n s i n g S h a p e ; 
 u s i n g   S c e n S i m : : S e n s i n g S h a r e d I n f o T y p e ; 
 u s i n g   S c e n S i m : : S e n s i n g M o d e l ; 
 
 c l a s s   A g e n t V a l u e F o r m u l a ; 
 s t r u c t   A g e n t S t a t u s C h a n g e E v e n t ; 
 c l a s s   A g e n t P r o f i l e A n d T a s k T a b l e ; 
 
 c o n s t   d o u b l e   M i n S t e p D i s t a n c e T o C o u n t I n S t a t s M e t e r s   =   1 e - 1 0 ; 
 
 b o o l   A S t r i n g S t a r t s W i t h ( c o n s t   s t r i n g &   a L i n e ,   c o n s t   s t r i n g &   a S t r i n g ) ; 
 
 s t r u c t   L o c a t i o n I n f o   { 
         b o o l   i s I d ; 
         A g e n t L o c a t i o n C h o i c e T y p e   l o c a t i o n C h o i c e T y p e ; 
         s t r i n g   l o c a t i o n N a m e ; 
         s t r i n g   n e a r e s t C h o i c e B a s e L o c a t i o n N a m e ; 
 
         L o c a t i o n I n f o ( ) 
                 : 
                 i s I d ( f a l s e ) , 
                 l o c a t i o n C h o i c e T y p e ( A G E N T _ L O C A T I O N _ C H O I C E _ R A N D O M ) 
         { } 
 
         L o c a t i o n I n f o ( 
                 c o n s t   b o o l   i n i t I s I d , 
                 c o n s t   A g e n t L o c a t i o n C h o i c e T y p e &   i n i t L o c a t i o n C h o i c e T y p e , 
                 c o n s t   s t r i n g &   i n i t L o c a t i o n N a m e ) 
                 : 
                 i s I d ( i n i t I s I d ) , 
                 l o c a t i o n C h o i c e T y p e ( i n i t L o c a t i o n C h o i c e T y p e ) , 
                 l o c a t i o n N a m e ( i n i t L o c a t i o n N a m e ) 
         { } 
 } ; 
 
 
 t e m p l a t e   < t y p e n a m e   I d T y p e ,   t y p e n a m e   V a l u e T y p e > 
 c l a s s   L a b e l M a p   { 
 p u b l i c : 
         I d T y p e   G e t I d ( c o n s t   s t r i n g &   n a m e )   c o n s t   { 
                 t y p e d e f   m a p < s t r i n g ,   s i z e _ t > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
                 I t e r T y p e   i t e r   =   i d s . f i n d ( n a m e ) ; / / M a k e L o w e r C a s e S t r i n g ( n a m e ) ) ; 
 
                 i f   ( i t e r   = =   i d s . e n d ( ) )   { 
                         c e r r   < <   " E r r o r :   C o u l d n ' t   f i n d   a n   a g e n t   p r o f i l e   p a r a m e t e r :   "   < <   n a m e   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 r e t u r n   I d T y p e ( ( * i t e r ) . s e c o n d ) ; 
         } 
 
         I d T y p e   G e t I d ( c o n s t   s t r i n g &   n a m e )   { 
 
                 / / c o n s t   s t r i n g   l o w e r N a m e   =   M a k e L o w e r C a s e S t r i n g ( n a m e ) ; 
 
                 i f   ( ( * t h i s ) . C o n t a i n s ( n a m e ) )   { 
                         r e t u r n   ( I d T y p e ) ( i d s [ n a m e ] ) ; 
                 }   e l s e   { 
                         c o n s t   I d T y p e   i d   =   ( I d T y p e ) ( i d s . s i z e ( ) ) ; 
 
                         i d s [ n a m e ]   =   i d ; 
                         l a b e l s . p u s h _ b a c k ( n a m e ) ; 
                         v a l u e s . p u s h _ b a c k ( V a l u e T y p e ( ) ) ; 
 
                         r e t u r n   i d ; 
                 } 
         } 
 
         b o o l   C o n t a i n s ( c o n s t   s t r i n g &   n a m e )   c o n s t   { 
                 r e t u r n   ( i d s . f i n d ( M a k e L o w e r C a s e S t r i n g ( n a m e ) )   ! =   i d s . e n d ( ) ) ; 
         } 
 
         c o n s t   V a l u e T y p e &   o p e r a t o r [ ] ( c o n s t   I d T y p e &   i d )   c o n s t   {   r e t u r n   v a l u e s . a t ( s i z e _ t ( i d ) ) ;   } 
 
         V a l u e T y p e &   o p e r a t o r [ ] ( c o n s t   s t r i n g &   n a m e )   { 
                 t y p e d e f   m a p < s t r i n g ,   s i z e _ t > : : i t e r a t o r   I t e r T y p e ; 
 
                 / / c o n s t   s t r i n g   l o w e r N a m e   =   M a k e L o w e r C a s e S t r i n g ( n a m e ) ; 
 
                 I t e r T y p e   i t e r   =   i d s . f i n d ( n a m e ) ; 
 
                 i f   ( i t e r   = =   i d s . e n d ( ) )   { 
                         i d s [ n a m e ]   =   v a l u e s . s i z e ( ) ; 
                         l a b e l s . p u s h _ b a c k ( n a m e ) ; 
                         v a l u e s . p u s h _ b a c k ( V a l u e T y p e ( ) ) ; 
                         r e t u r n   v a l u e s . b a c k ( ) ; 
                 } 
 
                 r e t u r n   v a l u e s [ ( * i t e r ) . s e c o n d ] ; 
         } 
 
         c o n s t   V a l u e T y p e &   o p e r a t o r [ ] ( c o n s t   s t r i n g &   n a m e )   c o n s t   { 
                 t y p e d e f   m a p < s t r i n g ,   s i z e _ t > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
                 I t e r T y p e   i t e r   =   i d s . f i n d ( n a m e ) ; 
 
                 i f   ( i t e r   = =   i d s . e n d ( ) )   { 
                         c e r r   < <   " E r r o r :   C o u l d n ' t   f i n d   a n   a g e n t   p r o f i l e   p a r a m e t e r :   "   < <   n a m e   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
 
                 r e t u r n   v a l u e s . a t ( ( * i t e r ) . s e c o n d ) ; 
         } 
 
         V a l u e T y p e &   o p e r a t o r [ ] ( c o n s t   I d T y p e &   i d )   {   r e t u r n   v a l u e s . a t ( i d ) ;   } 
 
         c o n s t   s t r i n g &   G e t L a b e l ( c o n s t   I d T y p e &   i d )   c o n s t   {   r e t u r n   l a b e l s [ i d ] ;   } 
 
         s i z e _ t   S i z e ( )   c o n s t   {   r e t u r n   v a l u e s . s i z e ( ) ;   } 
         s i z e _ t   s i z e ( )   c o n s t   {   r e t u r n   v a l u e s . s i z e ( ) ;   } 
 
         b o o l   e m p t y ( )   c o n s t   {   r e t u r n   v a l u e s . e m p t y ( ) ;   } 
 
 p r i v a t e : 
         m a p < s t r i n g ,   s i z e _ t >   i d s ; 
         v e c t o r < s t r i n g >   l a b e l s ; 
         v e c t o r < V a l u e T y p e >   v a l u e s ; 
 } ; 
 
 
 c l a s s   A g e n t   { 
 p u b l i c : 
         A g e n t ( 
                 M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                 c o n s t   G l o b a l N e t w o r k i n g O b j e c t B a g &   i n i t G l o b a l N e t w o r k i n g O b j e c t B a g , 
                 c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
                 c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r ) ; 
         ~ A g e n t ( ) ; 
 
         s t a t i c   s h a r e d _ p t r < A g e n t >   C r e a t e M a s t e r A g e n t ( 
                 M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                 c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r ) ; 
 
         s t a t i c   s h a r e d _ p t r < A g e n t >   C r e a t e T a x i D r i v e r A g e n t ( 
                 M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                 c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
                 c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
                 c o n s t   s h a r e d _ p t r < T a x i > &   i n i t T a x i P t r ) ; 
 
         s t a t i c   s h a r e d _ p t r < A g e n t >   C r e a t e B u s D r i v e r A g e n t ( 
                 M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                 c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
                 c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e > &   i n i t V e h i c l e P t r , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
                 c o n s t   s h a r e d _ p t r < B u s > &   i n i t B u s P t r ) ; 
 
         s t a t i c   s h a r e d _ p t r < A g e n t >   C r e a t e T r a i n D r i v e r A g e n t ( 
                 M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                 c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
                 c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
                 c o n s t   s h a r e d _ p t r < T r a i n > &   i n i t T r a i n P t r ) ; 
 
         S i m T i m e   C a l c u l a t e W a k e u p T i m e ( ) ; 
 
         v o i d   M o v e N e x t S t a t e s T o C u r r e n t ( ) ; 
 
         v o i d   I n c r e m e n t T i m e ( ) ; 
 
         / / O b j e c t M o b i l i t y P o s i t i o n   G e t P o s i t i o n ( c o n s t   S i m T i m e )   { 
         / /         ( s t a t u s [ n e x t S t e p ] . p o s   -   s t a t u s [ l a s t S t e p ] . p o s ( ) )   *   c o m p l e t i o n R a t i o n   +   s t a t u s [ l a s t S t e p ] . p o s ( ) ; 
         / / } 
 
         b o o l   I s D e l e t e d A f t e r E n d O f T i m e S t e p ( )   c o n s t   {   r e t u r n   i s D e l e t e d A t T h e E n d O f T i m e S t e p ;   } 
 
         A g e n t I d T y p e   G e t A g e n t I d ( )   c o n s t   {   r e t u r n   a g e n t I d ;   } 
 
         b o o l   H a s C a r ( )   c o n s t   {   r e t u r n   ( v e h i c l e P t r   ! =   n u l l p t r ) ;   } 
         b o o l   H a s B i c y c l e ( )   c o n s t   {   r e t u r n   h a s B i c y c l e ;   } 
 
         s h a r e d _ p t r < V e h i c l e >   G e t V e h i c l e ( )   c o n s t   {   r e t u r n   v e h i c l e P t r ;   } 
 
         v o i d   O u t p u t T r a c e ( c o n s t   s t r i n g &   a S t r i n g )   c o n s t ; 
 
         s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e >   G e t S i m E n g i n e I n t e r f a c e P t r ( )   c o n s t   {   r e t u r n   s i m E n g i n e I n t e r f a c e P t r ;   } 
 
         s h a r e d _ p t r < O b j e c t M o b i l i t y M o d e l >   G e t M o b i l i t y M o d e l P t r ( )   c o n s t   {   r e t u r n   m o b i l i t y M o d e l P t r ;   } 
 
         s h a r e d _ p t r < A g e n t P r o f i l e >   G e t P r o f i l e P t r ( )   c o n s t   {   r e t u r n   p r o f i l e P t r ;   } 
 
 
         v o i d   A d d C o m m u n i c a t i o n N o d e ( c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) ; 
         v o i d   D e l e t e C o m m u n i c a t i o n N o d e ( c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) ; 
 
         v o i d   R e c a l c u l a t e R o u t e ( 
                 c o n s t   S i m T i m e &   r e c a l c u l a t e S t a r t T i m e , 
                 c o n s t   A g e n t B e h a v i o r T y p e &   i n i t R e c a l c u l a t e R o u t e W i t h B e h a v i o r   =   A G E N T _ B E H A V I O R _ A N Y ) ; 
 
         v o i d   S e t C h a n g e d B y M e e t i n g ( b o o l   i n p u t ) ; 
 
         v o i d   O u t p u t T r a c e E v e n t ( ) ; 
 
         v o i d   G e t S t a r t A n d D e s t V e r t e x P a i r s ( 
                 c o n s t   V e r t e x I d T y p e &   p r i o r i t i z e d S t a r t V e r t e x I d , 
                 c o n s t   V e r t e x I d T y p e &   p r i o r i t i z e d D e s t V e r t e x I d , 
                 v e c t o r < V e r t e x I d T y p e > &   s t a r t V e r t e x I d s , 
                 v e c t o r < V e r t e x I d T y p e > &   d e s t V e r t e x I d s ) ; 
 
         v o i d   G e t N e a r R o u t e S e a r c h C a n d i d a t e V e r t e x I d s ( 
                 c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
                 c o n s t   V e r t e x &   p o s i t i o n , 
                 c o n s t   V e r t e x I d T y p e &   p r i o r i t i z e d D e s t V e r t e x I d , 
                 v e c t o r < V e r t e x I d T y p e > &   d e s t V e r t e x I d s ) ; 
 
         v o i d   R e a d y T o D e s t r u c t ( ) ; 
 
 p r i v a t e : 
         A g e n t ( 
                 M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                 c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   i n i t A g e n t G i s P t r , 
                 c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m > &   i n i t R o u t e S e a r c h S u b s y s t e m P t r , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e N o d e > &   i n i t V e h i c l e N o d e P t r , 
                 c o n s t   s h a r e d _ p t r < V e h i c l e > &   i n i t V e h i c l e P t r   =   s h a r e d _ p t r < V e h i c l e > ( ) ) ; 
 
         A g e n t ( 
                 M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                 c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e > &   i n i t S i m E n g i n e I n t e r f a c e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   i n i t P r o f i l e P t r , 
                 c o n s t   s h a r e d _ p t r < A g e n t T a s k T a b l e > &   i n i t T a s k T a b l e P t r ) ; 
 
         v o i d   E x e c u t e N e w T a s k I f N e c e s s a r y ( ) ; 
 
         v o i d   A p p l y S t a t u s C h a n g e s A n d I n s t a n t i a t e A p p l i c a t i o n s ( ) ; 
         v o i d   A p p l y A d d i t i o n a l S t a t u s C h a n g e s ( c o n s t   A g e n t A d d i t i o n a l S t a t u s C h a n g e &   a d d i t i o n a l S t a t u s C h a n g e ) ; 
         v o i d   A p p l y S t a t u s C h a n g e s ( c o n s t   v e c t o r < p a i r < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a >   > &   s t a t u s C h a n g e s ) ; 
         v o i d   I n s t a n t i a t e A p p l i c a t i o n s ( 
                 c o n s t   m a p < D y n a m i c A p p l i c a t i o n I d T y p e ,   D y n a m i c A p p l i c a t i o n D e f i n i t i o n > &   a p p l i c a t i o n S p e c i f i c a t i o n s ) ; 
 
 
         v o i d   I n i t i a l i z e S t a t u s W i t h ( 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
                 c o n s t   b o o l   c a l c u l a t e C a r A n d B i c y c l e P r o b a b i l i t y , 
                 b o o l &   h a s C a r ) ; 
 
         v o i d   A s s i g n C u r r e n t T a s k ( ) ; 
         v o i d   A s s i g n I n t e r r u p t T a s k ( ) ; 
         v o i d   G o T o N e x t B e h a v i o r I f P o s s i b l e ( ) ; 
 
         v o i d   D e c i d e C u r r e n t B e h a v i o r ( ) ; 
         v o i d   I n c r e m e n t C u r r e n t B e h a v i o r T i m e ( ) ; 
 
         v o i d   U p d a t e H e a l t h F a c t o r ( ) ; 
         v o i d   U p d a t e U t i l i t y ( ) ; 
 
         / / b o o l   N e e d T o R e c a l c u l a t e R o u t e ( )   c o n s t ; 
         v o i d   R e c a l c u l a t e B e h a v i o r I f N e c e s s a r y ( b o o l &   a s s i g n e d N e w B e h a v i o r ) ; 
 
         v o i d   D e c i d e R o u t e ( c o n s t   A g e n t B e h a v i o r T y p e &   s p e c i f i e d B e h a v i o r   =   A G E N T _ B E H A V I O R _ A N Y ,   b o o l   i s C h a n g e d B y M e e t i n g   =   f a l s e ) ; 
         v o i d   D e c i d e R o u t e ( 
                 
                 c o n s t   V e r t e x I d T y p e &   s t a r t V e r t e x I d , 
                 c o n s t   V e r t e x I d T y p e   e n d V e r t e x I d , 
                 c o n s t   A g e n t B e h a v i o r T y p e &   s p e c i f i e d B e h a v i o r , 
                 b o o l &   f o u n d R o u t e , 
                 b o o l   i s C h a n g e d B y M e e t i n g ) ; 
 
         b o o l   S h o u l d C h a n g e R o u t e I n C u r r e n t B e h a v i o r ( c o n s t   A g e n t B e h a v i o r T y p e &   s p e c i f i e d B e h a v i o r )   c o n s t ; 
 
         d o u b l e   C a l c u l a t e R o u t e W e i g h t ( c o n s t   A g e n t R o u t e L i s t &   a R o u t e ) ; 
 
         v o i d   S e t D e s t i n a t i o n ( 
                 c o n s t   G i s P o s i t i o n I d T y p e &   i n i t D e s t P o s i t i o n I d , 
                 c o n s t   b o o l   i n i t C a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e , 
                 c o n s t   b o o l   b y C o m m u n i c a t i o n ) ; 
         v o i d   S e t C u r r e n t D e s t i n a t i o n T o U n r e a c h a b l e P o s i t i o n ( ) ; 
         v o i d   A d d U n r e a c h a b l e P o s i t i o n s ( 
                 c o n s t   l i s t < G i s P o s i t i o n I d T y p e > &   u n r e a c h a b l e P o s i t i o n I d s , 
                 c o n s t   b o o l   b y C o m m u n i c a t i o n ) ; 
 
         v o i d   C h a n g e T o S p e c i f i c D e s t i n a t i o n ( 
                 c o n s t   G i s P o s i t i o n I d T y p e &   i n i t D e s t P o s i t i o n I d , 
                 c o n s t   V e r t e x I d T y p e &   i n i t D e s t V e r t e x I d , 
                 c o n s t   b o o l   b y C o m m u n i c a t i o n ) ; 
 
         v o i d   S e t V e r t e x I d ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d ) ; 
 
         b o o l   C u r r e n t T a s k H a s F i n i s h e d ( )   c o n s t ; 
         b o o l   H a s C u r r e n t T a s k ( )   c o n s t ; 
         b o o l   H a s P a r e n t ( )   c o n s t   {   r e t u r n   p a r e n t A g e n t I d   ! =   M A S T E R _ A N Y _ A G E N T _ I D ;   } 
         b o o l   W a i t i n g A t D e s t i n a t i o n E n t r a c e ( )   c o n s t ; 
         b o o l   W a i t i n g A t E n t r a n c e ( )   c o n s t ; 
         b o o l   O t h e r D e s t i n a t i o n S e e m s T o B e B e t t e r ( ) ; 
 
         c o n s t   V e r t e x &   G e t C u r r e n t P o s i t i o n ( )   c o n s t ; 
         c o n s t   V e r t e x &   G e t N e x t P o s i t i o n ( )   c o n s t ; 
 
         c o n s t   A g e n t T a s k &   C u r r e n t T a s k ( )   c o n s t ; 
         c o n s t   G i s P o s i t i o n I d T y p e &   G e t H o m e P o s i t i n I d ( )   c o n s t ; 
 
         f r i e n d   c l a s s   A g e n t R e s o u r c e ; 
         f r i e n d   c l a s s   M u l t i A g e n t S i m u l a t o r ; 
 
         M u l t i A g e n t S i m u l a t o r *   s i m u l a t o r P t r ; 
         s h a r e d _ p t r < M u l t i A g e n t G i s >   t h e A g e n t G i s P t r ; 
         s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e >   t h e P u b l i c V e h i c l e T a b l e P t r ; 
         s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m >   t h e R o u t e S e a r c h S u b s y s t e m P t r ; 
 
         s t a t i c   c o n s t   s t r i n g   m o d e l N a m e ; 
         c o n s t   A g e n t I d T y p e   a g e n t I d ; 
         c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e >   s i m E n g i n e I n t e r f a c e P t r ; 
         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e >   p r o f i l e P t r ; 
         s h a r e d _ p t r < A g e n t T a s k T a b l e >   t a s k T a b l e P t r ; 
 
         b o o l   i s D e l e t e d A t T h e E n d O f T i m e S t e p ; 
 
         A g e n t S t a t u s   s t a t u s ; 
         s h a r e d _ p t r < V e h i c l e >   v e h i c l e P t r ; 
         b o o l   h a s B i c y c l e ; 
 
         / / / A d d e d   D e c e m b e r   1 6   2 0 2 1 
         b o o l   C h a n g e d B y M e e t i n g   =   f a l s e ; 
 
         S i m T i m e   c u r r e n t T a s k S t a r t T i m e ; 
         S i m T i m e   c u r r e n t T a s k E n d T i m e ; 
         b o o l   i s T a s k I n i t i a l i z e d ; 
         d e q u e < V e r t e x I d T y p e >   s h o u l d P a s s V e r t e x I d s ; 
 
         p r i o r i t y _ q u e u e _ s t a b l e < A g e n t S t a t u s C h a n g e E v e n t >   t i m e L i n e S t a t u s C h a n g e E v e n t s ; 
         s i z e _ t   c u r r e n t T a s k N u m b e r ; 
 
         b o o l   c u r r e n t I s I n t e r r u p t T a s k ; 
         s i z e _ t   c u r r e n t I n t e r r u p t T a s k N u m b e r ; 
 
         T i m e T o S e a r c h R o u t e   t i m e T o S e a r c h R o u t e ; 
         / / v e c t o r < p a i r < G i s P o s i t i o n I d T y p e ,   V e r t e x I d T y p e >   >   d e s t i n a t i o n s ; 
         V e r t e x I d T y p e   d e s t V e r t e x I d ; 
         G i s P o s i t i o n I d T y p e   d e s t P o s i t i o n I d ; 
         G i s P o s i t i o n I d T y p e   e x t r a D e s t P o i I d ; / / P O I   o n   d e s t i n a t i o n   p a r k / b u i l d i n g 
 
         A g e n t B e h a v i o r T y p e   l a s t T i m e s t e p B e h a v i o r T y p e ; 
 
         b o o l   c a n C h a n g e T o O t h e r D e s t i n a t i o n C a n d i d a t e ; 
         s e t < G i s P o s i t i o n I d T y p e >   u n r e a c h a b l e D e s t i n a t i o n I d s ; 
 
         R o u t e N u m b e r T y p e   c u r r e n t R o u t e N u m b e r ; 
         A g e n t R o u t e L i s t   c u r r e n t R o u t e L i s t ; 
         / / l i s t < s h a r e d _ p t r < A g e n t R o u t e >   > : : i t e r a t o r   c u r r e n t R o u t e I t e r ; 
 
         G i s P o s i t i o n I d T y p e   h o m e P o s i t i o n I d ; 
 
         s h a r e d _ p t r < A g e n t B e h a v i o r >   c u r r e n t B e h a v i o r P t r ; 
         V e r t e x I d T y p e   l a s t V e r t e x I d ; 
 
         / /   D e s i r e d N e x t P o s i t i o n I d   ! =   C u r r e n t P o s i t i o n I D   o n l y   w h e n   q u e u e d . 
         G i s P o s i t i o n I d T y p e   d e s i r e d N e x t P o s i t i o n I d ; 
         G i s P o s i t i o n I d T y p e   c u r r e n t P o s i t i o n I d ; 
 
         G i s P o s i t i o n I d T y p e   e x t r a C u r r e n t P o i I d ; 
 
         S i m T i m e   e n t r a n c e W a i t S t a r t T i m e ; 
 
         d o u b l e   d i r e c t i o n R a d i a n s ; 
 
         S i m T i m e   c u r r e n t B e h a v i o r S t a r t T i m e ; 
         A g e n t H e a l t h O r U t i l i t y F a c t o r   h e a l t h O r U t i l i t y F a c t o r ; 
 
         S i m T i m e   l a s t R o u t e C a l c u l a t e d T i m e ; 
         S i m T i m e   l a s t P a t h Q u e r y T r i g g e r T i m e ; 
 
         b o o l   r e c a l c u l a t e R o u t e ; 
         A g e n t B e h a v i o r T y p e   r e c a l c u l a t e R o u t e W i t h B e h a v i o r ; 
         s e t < A g e n t B e h a v i o r T y p e >   n o t A v a i l a b l e B e h a v o r T y p e s F o r N e x t R o u t e C a l c u l a t i o n ; 
 
         S i m T i m e   l a s t D e l a y ; 
         u i n t 3 2 _ t   u t i l i t y 1 C a l c u l a t i o n C o u n t ; 
         u i n t 3 2 _ t   u t i l i t y 2 C a l c u l a t i o n C o u n t ; 
 
         A g e n t R o u t e C o s t   c u r r e n t B e h a v i o r C o s t ; 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r   a R a n d o m N u m b e r G e n e r a t o r ; / /   f o r   g e n e r a l   c a s e 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r   a R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ; 
 
         s t a t i c   c o n s t   i n t   S E E D _ H A S H I N G   =   7 3 8 8 5 2 9 ; 
         s t a t i c   c o n s t   i n t   S E E D _ H A S H I N G _ F O R _ D E S T I N A T I O N _ C H O I C E   =   5 4 3 6 3 6 ; 
 
         s t a t i c   c o n s t   i n t   S E E D _ H A S H I N G _ F O R _ S C E N A R I O _ G E N E R A T I O N _ L O C A T I O N _ I N I T   =   4 7 2 6 6 5 0 ; 
         s t a t i c   c o n s t   i n t   S E E D _ H A S H I N G _ F O R _ S C E N A R I O _ G E N E R A T I O N _ S T A T U S _ I N I T   =   3 8 8 4 8 7 4 ; 
 
         m a p < s i z e _ t ,   s h a r e d _ p t r < B u s T i c k e t >   >   b u s T i c k e t P t r s ; 
 
         A g e n t I d T y p e   p a r e n t A g e n t I d ; 
         l i s t < s h a r e d _ p t r < A g e n t >   >   c h i l d A g e n t P t r s ; 
 
         s h a r e d _ p t r < V e h i c l e N o d e >   v e h i c l e N o d e P t r ; 
 
         / /   h u m a n   i n t e r f a c e   f o r   s e e i n g ,   t a l k i n g , . . . 
         s h a r e d _ p t r < S h a p e S e n s i n g M o d e l >   h u m a n I n t e r f a c e P t r ; 
 
         / /   n e t w o r k   i n t e r f a c e 
         s e t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   >   c o m m u n i c a t i o n N o d e P t r s ; 
         s h a r e d _ p t r < O b j e c t M o b i l i t y M o d e l >   m o b i l i t y M o d e l P t r ; 
 
         s h a r e d _ p t r < R e a l S t a t i s t i c >   u t i l i t y 1 S t a t P t r ; 
         s h a r e d _ p t r < R e a l S t a t i s t i c >   u t i l i t y 2 S t a t P t r ; 
 
         s h a r e d _ p t r < R e a l S t a t i s t i c >   t r a v e l D i s t a n c e S t a t P t r ; 
         s h a r e d _ p t r < R e a l S t a t i s t i c >   t r a v e l T i m e S t a t P t r ; 
         s h a r e d _ p t r < C o u n t e r S t a t i s t i c >   n u m b e r N o R o u t e S t a t P t r ; 
         s h a r e d _ p t r < C o u n t e r S t a t i s t i c >   n u m b e r R o u t e C a l c u l a t e T i m e S t a t P t r ; 
 
         T r a c e V a l u e < d o u b l e >   u t i l i t y 1 T r a c e ; 
         T r a c e V a l u e < d o u b l e >   u t i l i t y 2 T r a c e ; 
 
         T r a c e V a l u e < d o u b l e >   c o n g e s t i o n T r a c e ; 
 
         T r a c e V a l u e < d o u b l e >   t r a v e l D i s t a n c e T r a c e ; 
         T r a c e V a l u e < d o u b l e >   t r a v e l T i m e T r a c e ; 
 
         T r a c e V a l u e < u i n t 3 2 _ t >   d e s t i n a t i o n C h a n g e T r a c e ; 
         T r a c e V a l u e < u i n t 3 2 _ t >   d e s t i n a t i o n C h a n g e B y C o m m u n i c a t i o n T r a c e ; 
 } ; / / A g e n t / / 
 
 
 
 c l a s s   A g e n t R e s o u r c e   { 
 p u b l i c : 
         A g e n t R e s o u r c e ( )   :   a g e n t P t r ( n u l l p t r )   { } 
         A g e n t R e s o u r c e ( A g e n t *   i n i t A g e n t P t r )   :   a g e n t P t r ( i n i t A g e n t P t r )   { } 
         A g e n t R e s o u r c e ( c o n s t   s h a r e d _ p t r < A g e n t > &   i n i t A g e n t P t r )   :   a g e n t P t r ( i n i t A g e n t P t r . g e t ( ) )   { } 
 
         b o o l   I s A v a i l a b l e ( )   c o n s t   {   r e t u r n   ( a g e n t P t r   ! =   n u l l p t r ) ;   } 
         v o i d   C h e c k A g e n t A v a i l a b i l i t y ( )   c o n s t   { 
                 i f   ( ! ( * t h i s ) . I s A v a i l a b l e ( ) )   { 
                         c e r r   < <   " A g e n t   r e s o u r c e   i s   e m p t y .   A g e n t R e s o u r c e   A P I s   i s   i n i t i a l i z e d   a f t e r   a n   a g e n t   i n i t i a l i z a t i o n   t i m e   s t e p . "   < <   e n d l ; 
                         e x i t ( 1 ) ; 
                 } 
         } 
 
         S i m T i m e   C u r r e n t T i m e ( )   c o n s t ; 
         S i m T i m e   C u r r e n t B e h a v i o r S p e n t T i m e ( )   c o n s t ; 
 
         A g e n t I d T y p e   A g e n t I d ( )   c o n s t   {   ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ;   r e t u r n   a g e n t P t r - > a g e n t I d ;   } 
         A g e n t P r o f i l e T y p e   P r o f i l e T y p e ( )   c o n s t ; 
         s t r i n g   G e t P r o f i l e N a m e ( )   c o n s t ; 
 
         A g e n t U s e r T y p e   U s e r T y p e ( )   c o n s t ; 
         A g e n t M o b i l i t y C l a s s T y p e   M o b i l i t y C l a s s ( )   c o n s t ; 
         A g e n t T i c k e t T y p e   T i c k e t T y p e ( )   c o n s t ; 
 
         c o n s t   G i s P o s i t i o n I d T y p e &   D e s t P o s i t i o n I d ( )   c o n s t ; 
         c o n s t   G i s P o s i t i o n I d T y p e &   E x t r a D e s t P o i I d ( )   c o n s t ; 
         c o n s t   G i s P o s i t i o n I d T y p e &   H o m e P o s i t i o n I d ( )   c o n s t ; 
         R o u t e N u m b e r T y p e   C u r r e n t R o u t e N u m b e r ( )   c o n s t ; 
         c o n s t   A g e n t R o u t e &   C u r r e n t R o u t e ( )   c o n s t ; 
         S t o p I d T y p e   G e t N e x t R o u t e S t o p I d ( )   c o n s t ; 
         c o n s t   s e t < G i s P o s i t i o n I d T y p e > &   U n r e a c h a b l e D e s t i n a t i o n I d s ( )   c o n s t ; 
 
         c o n s t   A g e n t T a s k P u r p o s e T y p e &   C u r r e n t P u r p o s e ( )   c o n s t ; 
 
         c o n s t   V e r t e x I d T y p e &   L a s t V e r t e x I d ( )   c o n s t   {   ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ;     r e t u r n   a g e n t P t r - > l a s t V e r t e x I d ;   } 
 
         c o n s t   G i s P o s i t i o n I d T y p e &   G e t C u r r e n t P o s i t i o n I d ( )   c o n s t   { 
                 ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
                 r e t u r n   a g e n t P t r - > c u r r e n t P o s i t i o n I d ; 
         } 
 
         c o n s t   G i s P o s i t i o n I d T y p e &   G e t D e s i r e d P o s i t i o n I d ( )   c o n s t   { 
                 ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ; 
 
                 r e t u r n   a g e n t P t r - > d e s i r e d N e x t P o s i t i o n I d ; 
         } 
 
 
         c o n s t   V e r t e x I d T y p e &   D e s t V e r t e x I d ( )   c o n s t   {   ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ;     r e t u r n   a g e n t P t r - > d e s t V e r t e x I d ;   } 
 
         c o n s t   A g e n t S t a t u s &   S t a t u s ( )   c o n s t   {   ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ;   r e t u r n   a g e n t P t r - > s t a t u s ;   } 
         c o n s t   V e r t e x &   P o s i t i o n ( )   c o n s t ; 
 
         b o o l   C h a n g e d B y M e e t i n g ( )   c o n s t {   ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ;     r e t u r n   a g e n t P t r - > C h a n g e d B y M e e t i n g ; } 
 
         A g e n t R o u t e L i s t   C u r r e n t R o u t e L i s t ( )   c o n s t { ( * t h i s ) . C h e c k A g e n t A v a i l a b i l i t y ( ) ;     r e t u r n   a g e n t P t r - > c u r r e n t R o u t e L i s t ; } 
 
         O b j e c t M o b i l i t y P o s i t i o n   M o b i l i t y P o s i t i o n ( )   c o n s t ; 
         O b j e c t M o b i l i t y P o s i t i o n   M o b i l i t y P o s i t i o n F o r T i m e ( c o n s t   S i m T i m e &   t i m e )   c o n s t ; 
         d o u b l e   V a l u e ( c o n s t   A g e n t S t a t u s I d T y p e &   i d )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ i d ] ;   } 
 
         A g e n t B e h a v i o r T y p e   G e t L a s t T i m e s t e p B e h a v i o r T y p e ( )   c o n s t   {   r e t u r n   ( a g e n t P t r - > l a s t T i m e s t e p B e h a v i o r T y p e ) ;   } 
         A g e n t B e h a v i o r T y p e   G e t B e h a v i o r T y p e ( )   c o n s t ; 
 
         i n t   A g e ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < i n t > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ A G E ] ) ;   } 
         d o u b l e   W a l k S p e e d M e t e r s P e r S e c ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ W A L K _ S P E E D ] ;   } 
         d o u b l e   B i c y c l e S p e e d M e t e r s P e r S e c ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ B I C Y C L E _ S P E E D ] ;   } 
         d o u b l e   M a x V e h i c l e S p e e d M e t e r s P e r S e c ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ V E H I C L E _ S P E E D ] ;   } 
 
         d o u b l e   L a s t D e l a y Q u e r y T r i g g e r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ L A S T _ D E L A Y _ Q U E R Y _ T R I G G E R ] ;   } 
         d o u b l e   N e x t D e l a y Q u e r y T r i g g e r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ N E X T _ D E L A Y _ Q U E R Y _ T R I G G E R ] ;   } 
         d o u b l e   T r i p D e l a y Q u e r y T r i g g e r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ T R I P _ D E L A Y _ Q U E R Y _ T R I G G E R ] ;   } 
         d o u b l e   V e h i c l e D e l a y Q u e r y T r i g g e r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ V E H I C L E _ D E L A Y _ Q U E R Y _ T R I G G E R ] ;   } 
         d o u b l e   C o n g e s t i o n Q u e r y T r i g g e r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ C O N G E S T I O N _ Q U E R Y _ T R I G G E R ] ;   } 
 
         d o u b l e   U t i l i t y 1 Q u e r y T r i g g e r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ U T I L I T Y 1 _ Q U E R Y _ T R I G G E R ] ;   } 
         d o u b l e   U t i l i t y 2 Q u e r y T r i g g e r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ U T I L I T Y 2 _ Q U E R Y _ T R I G G E R ] ;   } 
 
         S i m T i m e   M i n P a t h Q u e r y I n t e r v a l ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < S i m T i m e > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M I N _ P A T H _ Q U E R Y _ I N T E R V A L ] ) * S E C O N D ;   } 
         d o u b l e   P a t h Q u e r y P r o b a b i l i t y ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ P A T H _ Q U E R Y _ P R O B A B I L I T Y ] ;   } 
         d o u b l e   M i s s e d V e h i c l e P a t h Q u e r y P r o b a b i l i t y ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M I S S E D _ V E H I C L E _ P A T H _ Q U E R Y _ P R O B A B I L I T Y ] ;   } 
 
         d o u b l e   G a s o l i n C o s t P e r M e t e r s ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ G A S O L I N _ C O S T _ P E R _ M E T E R S ] ;   } 
         d o u b l e   U t i l i t y 1 ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ U T I L I T Y 1 ] ;   } 
         d o u b l e   U t i l i t y 2 ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ U T I L I T Y 2 ] ;   } 
 
         S i m T i m e   R i d i n g T i m e ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < S i m T i m e > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ R I D I N G _ T I M E ] ) * S E C O N D ;   } 
         d o u b l e   S e e i n g P e d e s t r i a n P r o b a b i l i t y ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ S E E I N G _ P E D E S T R I A N _ P R O B A B I L I T Y ] ;   } 
         d o u b l e   T i m e H e a d w a y ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ T I M E _ H E A D W A Y ] ;   } 
         d o u b l e   M i n V e h i c l e G a p ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M I N _ V E H I C L E _ G A P ] ;   } 
         d o u b l e   M a x A c c e l e r a t i o n ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ A C C E L E R A T I O N ] ;   } 
         d o u b l e   M a x D e c e l e r a t i o n ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ D E C E L E R A T I O N ] ;   } 
         d o u b l e   M a x B r a k i n g D e c c e l e r a t i o n ( )   c o n s t   {   r e t u r n     ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ B R A K I N G _ D E C C E L E R A T I O N ] ;   } 
         d o u b l e   A c c e l e r a t i o n E x p o n e n t ( )   c o n s t   {   r e t u r n     ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ A C C E L E R A T I O N _ E X P O N E N T ] ;   } 
         d o u b l e   S a v e A c c e l e r a t i o n ( )   c o n s t   {   r e t u r n     ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ S A V E _ D E C E L E R A T I O N ] ;   } 
         d o u b l e   M a x T u r n S p e e d M e t e r s P e r S e c ( )   c o n s t   {   r e t u r n     ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ M A X _ T U R N _ S P E E D ] ;   } 
 
         d o u b l e   L a n e C h a n g e A c c e l e r a t i o n T h r e s h o l d ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ L A N E _ C H A N G E _ A C C E L E R A T I O N _ T H R E S H O L D ] ;   } 
         d o u b l e   V e l o c i t y R a t i o G a p D i s t a n c e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ V E L O C I T Y _ R A T I O _ G A P _ D I S T A N C E ] ;   } 
         d o u b l e   O t h e r V e h i c l e E n t r a n c e T i m e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ O T H E R _ V E H I C L E _ E N A T R A N C E _ T I M E ] ;   } 
         d o u b l e   P a s s i v e Y i e l d T i m e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ P A S S I V E _ Y I E L D _ T I M E ] ;   } 
         d o u b l e   A c t i v e Y i e l d T i m e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ A C T I V E _ Y I E L D _ T I M E ] ;   } 
         d o u b l e   Y i e l d W a i t i n g T i m e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ Y I E L D _ W A I T I N G _ T I M E ] ;   } 
 
         d o u b l e   T o t a l T r a v e l D i s t a n c e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ T O T A L _ T R A V E L _ D I S T A N C E ] ;   } 
         d o u b l e   T o t a l T r a v e l T i m e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ T O T A L _ T R A V E L _ T I M E ] ;   } 
         d o u b l e   R o a d W i d t h W e i g h t ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ R O A D _ W I D T H _ W E I G H T ] ;   } 
         b o o l   I s D i s a s t e r M o d e ( )   c o n s t   {   r e t u r n   ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ D I S A S T E R ]   >   0 ) ;   } 
         S i m T i m e   R o u t e R e c a l c u l a t i o n T i m e ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < S i m T i m e > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ S T A T U S _ R O U T E _ R E C A L C U L A T I O N _ T I M E ] ) * S E C O N D ;   } 
 
         d o u b l e   A c c e p t a b l e W a l k D i s t a n c e T o C a r ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ A C C E P T A B L E _ W A L K _ D I S T A N C E _ T O _ C A R ] ;   } 
         d o u b l e   A c c e p t a b l e W a l k D i s t a n c e T o S t o p ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ A C C E P T A B L E _ W A L K _ D I S T A N C E _ T O _ S T O P ] ;   } 
 
         d o u b l e   M i n V e h i c l e R o u t e D i s t a n c e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ M I N _ V E H I C L E _ R O U T E _ D I S T A N C E ] ;   } 
         i n t   N u m b e r M a x R o u t e C a n d i d a t e s ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < i n t > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ N U M B E R _ M A X _ R O U T E _ C A N D I D A T E S ] ) ;   } 
         i n t   N u m b e r P e o p l e ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < i n t > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ N U M B E R _ P E O P L E ] ) ;   } 
         S i m T i m e   E n t r a n c e W a i t T i m e ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < S i m T i m e > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ E N T R A N C E _ W A I T _ T I M E ] ) * S E C O N D ;   } 
         S i m T i m e   V e h i c l e E n t r a n c e W a i t T i m e ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < S i m T i m e > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ V E H I C L E _ E N T R A N C E _ W A I T _ T I M E ] ) * S E C O N D ;   } 
         S i m T i m e   T a x i C a l l W a i t T i m e ( )   c o n s t   {   r e t u r n   s t a t i c _ c a s t < S i m T i m e > ( ( * t h i s ) . S t a t u s ( ) . v a l u e s [ A G E N T _ R E S E R V E D _ T A X I C A L L _ W A I T _ T I M E ] ) * S E C O N D ;   } 
 
         b o o l   W a i t i n g A t E n t r a n c e ( )   c o n s t ; 
         b o o l   E x c e e d e d W a i t E n t r a n c e T i m e ( )   c o n s t ; 
         b o o l   E x c e e d e d W a i t V e h i c l e E n t r a n c e T i m e ( )   c o n s t ; 
 
         V e h i c l e C o n s t a n t   M a k e V e h i c l e C o n s t a n t ( c o n s t   d o u b l e   v e h i c l e L e n g t h M e t e r s   =   D E F A U L T _ V E H I C L E _ L E N G T H _ M E T E R S )   c o n s t   { 
                 r e t u r n   V e h i c l e C o n s t a n t ( 
                         v e h i c l e L e n g t h M e t e r s * 0 . 5 , 
                         ( * t h i s ) . L a n e C h a n g e A c c e l e r a t i o n T h r e s h o l d ( ) , 
                         ( * t h i s ) . M a x A c c e l e r a t i o n ( ) , 
                         ( * t h i s ) . M a x D e c e l e r a t i o n ( ) , 
                         ( * t h i s ) . M a x B r a k i n g D e c c e l e r a t i o n ( ) , 
                         ( * t h i s ) . A c c e l e r a t i o n E x p o n e n t ( ) , 
                         ( * t h i s ) . S a v e A c c e l e r a t i o n ( ) , 
                         ( * t h i s ) . M a x T u r n S p e e d M e t e r s P e r S e c ( ) , 
                         ( * t h i s ) . M a x V e h i c l e S p e e d M e t e r s P e r S e c ( ) , 
                         ( * t h i s ) . M i n V e h i c l e G a p ( ) , 
                         ( * t h i s ) . T i m e H e a d w a y ( ) , 
                         ( * t h i s ) . V e l o c i t y R a t i o G a p D i s t a n c e ( ) , 
                         ( * t h i s ) . O t h e r V e h i c l e E n t r a n c e T i m e ( ) , 
                         ( * t h i s ) . P a s s i v e Y i e l d T i m e ( ) , 
                         ( * t h i s ) . A c t i v e Y i e l d T i m e ( ) , 
                         ( * t h i s ) . Y i e l d W a i t i n g T i m e ( ) , 
                         ( * t h i s ) . G a s o l i n C o s t P e r M e t e r s ( ) ) ; 
         } 
 
         S i m T i m e   L a s t D e l a y ( )   c o n s t ; 
         S i m T i m e   N e x t D e l a y ( )   c o n s t ; 
         S i m T i m e   T r i p D e l a y ( )   c o n s t ; 
         S i m T i m e   A r r i v a l D e l a y ( )   c o n s t ; 
 
         d o u b l e   C o n g e s t i o n ( )   c o n s t   {   r e t u r n   a g e n t P t r - > h e a l t h O r U t i l i t y F a c t o r . v a l u e s [ A G E N T _ H E A L T H _ F A C T O R _ C O N G E S T I O N ] ;   } 
 
         b o o l   H a s C a r ( )   c o n s t   {   r e t u r n   a g e n t P t r - > H a s C a r ( ) ;   } 
         b o o l   H a s B i c y c l e ( )   c o n s t   {   r e t u r n   a g e n t P t r - > h a s B i c y c l e ;   } 
         b o o l   C a n U s e B i c y c l e ( )   c o n s t   {   r e t u r n   ( * t h i s ) . H a s B i c y c l e ( ) ;   } 
         b o o l   I s P a t h Q u e r y T r i g g e r A v a i l a b l e ( 
                 c o n s t   d o u b l e   c o n g e s t i o n   =   0 , 
                 c o n s t   S i m T i m e &   v e h i c l e D e l a y   =   Z E R O _ T I M E )   c o n s t ; 
 
         c o n s t   V e h i c l e &   G e t V e h i c l e ( )   c o n s t   {   r e t u r n   * a g e n t P t r - > v e h i c l e P t r ;   } 
 
         v o i d   S e t L a s t P a t h Q u e r y T r i g g e r T i m e ( ) ; 
 
         b o o l   E x c e e d e d R o u t e R e c a l c u l a t i o n T i m e ( )   c o n s t ; 
 
 / /   s p e c i a l   f u n c t i o n   f o r   t a x i 
         v o i d   A s s i g n T a x i ( c o n s t   s h a r e d _ p t r < T a x i > &   i n i t T a x i P t r ) ; 
 
 / / p r i v a t e   f u n c t i o n s :   M U S T   n o t   c a l l   f r o m   o t h e r s 
 
         A g e n t S t a t u s &   S t a t u s ( )   {   r e t u r n   a g e n t P t r - > s t a t u s ;   } 
 
         v o i d   S e t P o s i t i o n ( c o n s t   V e r t e x &   p o s i t i o n ) ; 
         v o i d   S e t V e r t e x I d ( c o n s t   V e r t e x I d T y p e &   v e r t e x I d ) ; 
         v o i d   S e t C u r r e n t P o s i t i o n I d ( c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d ) ; 
         v o i d   S e t C u r r e n t P o s i t i o n I d ( c o n s t   G i s O b j e c t T y p e &   o b j e c t T y p e ,   c o n s t   V a r i a n t I d T y p e &   v a r i a n t I d ) ; 
         v o i d   S e t D e s i r e d N e x t P o s i t i o n I d ( c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d ) ; 
         v o i d   S e t D e s i r e d N e x t P o s i t i o n I d ( c o n s t   G i s O b j e c t T y p e &   o b j e c t T y p e ,   c o n s t   V a r i a n t I d T y p e &   v a r i a n t I d ) ; 
         v o i d   U p d a t e C u r r e n t P o s i t i o n I d T o D e s i r e d P o s i t i o n I d ( ) ; 
 
         v o i d   S e t E x t r a P o i I d ( c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d ) ; 
         v o i d   S e t D i r e c t i o n R a d i a n s ( c o n s t   d o u b l e   d i r e c t i o n R a d i a n s ) ; 
 
         v o i d   S e t C o n g e s t i o n ( c o n s t   d o u b l e   v a l u e ) ; 
 
         v o i d   R e c a l c u l a t e R o u t e ( c o n s t   S i m T i m e &   r e c a l c u l a t e S t a r t T i m e ) ; 
         v o i d   R e c a l c u l a t e R o u t e ( ) ; 
         v o i d   R e c a l c u l a t e R o u t e W i t h B e h a v i o r ( c o n s t   A g e n t B e h a v i o r T y p e &   b e h a v i o r ) ; 
 
         v o i d   R e c a l c u l a t e R o u t e W i t h N o t A v a i l a b l e B e h a v i o r S p e c i f i c a t i o n ( 
                 c o n s t   s e t < A g e n t B e h a v i o r T y p e > &   n o t A v a i l a b l e B e h a v i o r T y p e s ) ; 
         v o i d   A r r i v e d A t D e a d E n d N o t i f i c a t i o n ( ) ; 
         v o i d   U n r e a c h a b l e D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
         v o i d   A r r i v e d A t D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
         v o i d   E n t e r e d T o D e s t i n a t i o n N o t i f i c a t i o n ( ) ; 
         v o i d   A r r i v e d A t G i s P o s i t i o n N o t i f i c a t i o n ( ) ; 
 
         v o i d   S e t D e s t i n a t i o n ( 
                 c o n s t   V e r t e x &   p o s i t i o n , 
                 c o n s t   b o o l   b y C o m m u n i c a t i o n ) ; 
 
         v o i d   S e t D e s t i n a t i o n ( 
                 c o n s t   G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
                 c o n s t   V e r t e x &   p o s i t i o n , 
                 c o n s t   b o o l   b y C o m m u n i c a t i o n ) ; 
 
         v o i d   A d d U n r e a c h a b l e P o s i t i o n s ( c o n s t   l i s t < G i s P o s i t i o n I d T y p e > &   u n r e a c h a b l e P o s i t i o n I d s ,   c o n s t   b o o l   b y C o m m u n i c a t i o n ) ; 
 
         v o i d   R e c e i v e P h y s i c a l D a t a ( S e n s i n g S h a r e d I n f o T y p e &   b r o a d c a s t D a t a ) ; 
 
         v o i d   S e t O w n e r A g e n t ( 
                 c o n s t   A g e n t I d T y p e &   o w n e r A g e n t I d   =   M A S T E R _ A N Y _ A G E N T _ I D ) ; 
 
         v o i d   R e m o v e O w n e r A g e n t ( ) ; 
 
         v o i d   W a i t E n t r a n c e ( ) ; 
         v o i d   A l l o w e d E n t r a n c e ( ) ; 
         v o i d   E n d E n t r a n c e W a i t i n g ( ) ; 
 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   G e t R a n d o m N u m b e r G e n e r a t o r ( )   c o n s t ; 
         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   G e t R a n d o m N u m b e r G e n e r a t o r F o r D e s t i n a t i o n C h o i c e ( )   c o n s t ; 
 
         b o o l   o p e r a t o r = = ( c o n s t   A g e n t R e s o u r c e &   r i g h t )   c o n s t   {   r e t u r n   ( * t h i s ) . A g e n t I d ( )   = =   r i g h t . A g e n t I d ( ) ;   } 
         b o o l   o p e r a t o r < ( c o n s t   A g e n t R e s o u r c e &   r i g h t )   c o n s t   {   r e t u r n   ( * t h i s ) . A g e n t I d ( )   <   r i g h t . A g e n t I d ( ) ;   } 
 
 
         / /   f o r   d e b u g i n g 
         v o i d   O u t p u t T r a c e ( c o n s t   s t r i n g &   a S t r i n g )   c o n s t   {   r e t u r n   a g e n t P t r - > O u t p u t T r a c e ( a S t r i n g ) ;   } 
         c o n s t   V e r t e x &   D e b u g N e x t P o s i t i o n ( )   c o n s t ; 
 
 p r i v a t e : 
         A g e n t *   a g e n t P t r ; 
 } ; 
 
 c l a s s   A g e n t V a l u e F o r m u l a   { 
 p u b l i c : 
         A g e n t V a l u e F o r m u l a ( c o n s t   d o u b l e   i n i t D e f a u l t v a l u e   =   0 )   :   d e f a u l t V a l u e ( i n i t D e f a u l t v a l u e )   { } 
 
         A g e n t V a l u e F o r m u l a ( 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   s t a t u s V a l u e s , 
                 c o n s t   d o u b l e   s i m S t a r t T i m e S e c , 
                 c o n s t   s t r i n g &   a S t r i n g , 
                 m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   c h a r a c t o r I d s , 
                 c o n s t   d o u b l e   i n i t D e f a u l t v a l u e   =   0 ) ; 
 
         A g e n t V a l u e F o r m u l a ( 
                 c o n s t   s t r i n g &   a S t r i n g , 
                 c o n s t   d o u b l e   i n i t D e f a u l t v a l u e   =   0 ) ; 
 
         b o o l   I s N u l l ( )   c o n s t   {   r e t u r n   f o r m u l a U n i t s . e m p t y ( ) ;   } 
 
         d o u b l e   C a l c u l a t e D o u b l e ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   b o o l   c a l c u l a t e M a x V a l u e   =   f a l s e )   c o n s t ; 
 
         i n t   C a l c u l a t e I n t ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   b o o l   c a l c u l a t e M a x V a l u e   =   f a l s e )   c o n s t   { 
                 r e t u r n   s t a t i c _ c a s t < i n t > ( ( * t h i s ) . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r a n d G e n ,   c a l c u l a t e M a x V a l u e ) ) ; 
         } 
 
         S i m T i m e   C a l c u l a t e T i m e ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   b o o l   c a l c u l a t e M a x V a l u e   =   f a l s e )   c o n s t ; 
 
         d o u b l e   C a l c u l a t e U t i l i t y ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   A g e n t H e a l t h O r U t i l i t y F a c t o r &   h e a l t h O r U t i l i t y F a c t o r , 
                 c o n s t   A g e n t R o u t e C o s t &   c o s t )   c o n s t ; 
 
         c l a s s   F o r m u l a   { 
         p u b l i c : 
                 v i r t u a l   ~ F o r m u l a ( )   { } 
                 v i r t u a l   d o u b l e   o p e r a t o r ( ) ( 
                         c o n s t   v e c t o r < d o u b l e > &   v a l u e s , 
                         c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                         H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   =   0 ; 
         } ; 
 
         s t r i n g   G e t I n p u t F o r m u l a S t r i n g ( )   c o n s t   {   r e t u r n   i n p u t F o r m u l a S t r i n g ;   } 
 
 p r i v a t e : 
         t y p e d e f   s i z e _ t   F o r m u l a U n i t I d T y p e ; 
 
         s t a t i c   c o n s t   F o r m u l a U n i t I d T y p e   N O _ F O R M U L A _ U N I T _ I D   =   B A D _ S I Z E _ T ; 
 
         t y p e d e f   u i n t 8 _ t   F o r m u l a O p e r a t i o n T y p e ; 
         e n u m   { 
                 F O R M U L A _ O P E R A T I O N _ N O N E   =   0 , 
 
                 F O R M U L A _ O P E R A T I O N _ P L U S   =   1 , 
                 F O R M U L A _ O P E R A T I O N _ M I N U S   =   2 , 
                 F O R M U L A _ O P E R A T I O N _ D I V   =   3 , 
                 F O R M U L A _ O P E R A T I O N _ M U L T I   =   4 , 
                 F O R M U L A _ O P E R A T I O N _ M O D   =   5 , 
                 F O R M U L A _ O P E R A T I O N _ E _ P L U S   =   6 , 
                 F O R M U L A _ O P E R A T I O N _ E _ M I N U S   =   7 , 
 
                 F O R M U L A _ O P E R A T I O N _ L O G 1 0   =   8 , 
                 F O R M U L A _ O P E R A T I O N _ L O G N   =   9 , 
                 F O R M U L A _ O P E R A T I O N _ P O W   =   1 0 , 
                 F O R M U L A _ O P E R A T I O N _ M I N   =   1 1 , 
                 F O R M U L A _ O P E R A T I O N _ M A X   =   1 2 , 
                 F O R M U L A _ O P E R A T I O N _ S Q R T   =   1 3 , 
                 F O R M U L A _ O P E R A T I O N _ S I N   =   1 4 , 
                 F O R M U L A _ O P E R A T I O N _ C O S   =   1 5 , 
                 F O R M U L A _ O P E R A T I O N _ T A N   =   1 6 , 
                 F O R M U L A _ O P E R A T I O N _ A B S   =   1 7 , 
                 F O R M U L A _ O P E R A T I O N _ C E I L   =   1 8 , 
                 F O R M U L A _ O P E R A T I O N _ F L O O R   =   1 9 , 
                 F O R M U L A _ O P E R A T I O N _ P I   =   2 0 , 
                 F O R M U L A _ O P E R A T I O N _ E X P   =   2 1 , 
 
                 F O R M U L A _ O P E R A T I O N _ D I S T R I B U T I O N _ S T A R T   =   2 2 , 
 
                 F O R M U L A _ O P E R A T I O N _ U N I   =   2 2 , 
                 F O R M U L A _ O P E R A T I O N _ U N I D   =   2 3 , 
                 F O R M U L A _ O P E R A T I O N _ N O R M A L   =   2 4 , 
                 F O R M U L A _ O P E R A T I O N _ E X P _ D I S T R I B U T I O N   =   2 5 , 
                 F O R M U L A _ O P E R A T I O N _ P O I S S O N   =   2 6 , 
                 F O R M U L A _ O P E R A T I O N _ E R L A N G   =   2 7 , 
 
                 N U M B E R _ F O R M U L A _ T Y P E S , 
         } ; 
 
         s t r u c t   F o r m u l a U n i t   { 
                 F o r m u l a U n i t I d T y p e   u n i t I d ; 
                 F o r m u l a O p e r a t i o n T y p e   o p e r a t i o n ; 
                 v e c t o r < p a i r < F o r m u l a U n i t I d T y p e ,   d o u b l e >   >   v a l u e s ; 
 
                 F o r m u l a U n i t ( c o n s t   F o r m u l a U n i t I d T y p e &   i n i t U n i t I d ) 
                         : 
                         u n i t I d ( i n i t U n i t I d ) 
                 { } 
 
                 F o r m u l a U n i t ( 
                         c o n s t   F o r m u l a U n i t I d T y p e &   i n i t U n i t I d , 
                         c o n s t   F o r m u l a O p e r a t i o n T y p e &   i n i t O p e r a t i o n ) 
                         : 
                         u n i t I d ( i n i t U n i t I d ) , 
                         o p e r a t i o n ( i n i t O p e r a t i o n ) 
                 { } 
 
                 b o o l   C o m p l e t e d A l l C a l c u l a t i o n ( )   c o n s t ; 
         } ; 
 
         s t r i n g   i n p u t F o r m u l a S t r i n g ; 
         v e c t o r < F o r m u l a U n i t >   f o r m u l a U n i t s ; 
         d o u b l e   d e f a u l t V a l u e ; 
 
         / /   s h a r e d _ a r r a y 
         s t a t i c   c o n s t   s h a r e d _ p t r < F o r m u l a >   f o r m u l a P t r s [ ] ; 
 
         F o r m u l a U n i t &   G e t F o r m u l a U n i t ( c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d ) ; 
         c o n s t   F o r m u l a U n i t &   G e t F o r m u l a U n i t ( c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d )   c o n s t ; 
 
         F o r m u l a O p e r a t i o n T y p e   G e t F o r m u l a O p e r a t i o n ( 
                 c o n s t   s t r i n g &   f u n c t i o n S t r i n g , 
                 c o n s t   s i z e _ t   n u m b e r A r g u m e n t s )   c o n s t ; 
 
         v o i d   P r e c a l c u l a t e F o r m u l a U n i t ( c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d ) ; 
 
         d o u b l e   C a l c u l a t e ( 
                 c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   b o o l   c a l c u l a t e M a x V a l u e   =   f a l s e )   c o n s t ; 
 
         d o u b l e   C a l c u l a t e U t i l i t y ( 
                 c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   A g e n t H e a l t h O r U t i l i t y F a c t o r &   h e a l t h O r U t i l i t y F a c t o r , 
                 c o n s t   A g e n t R o u t e C o s t &   c o s t )   c o n s t ; 
 
         d o u b l e   C a l c u l a t e M a x ( 
                 c o n s t   F o r m u l a U n i t I d T y p e &   u n i t I d , 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
 
         F o r m u l a U n i t I d T y p e   A d d F o r m u l a U n i t R e c u r s i v e l y ( 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
                 c o n s t   d o u b l e   s i m S t a r t T i m e S e c , 
                 c o n s t   s t r i n g &   a S t r i n g , 
                 m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   c h a r a c t o r I d s ) ; 
 
         F o r m u l a U n i t I d T y p e   A d d F u n c t i o n U n i t R e c u r s i v e l y ( 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   p a r a m e t e r s , 
                 c o n s t   d o u b l e   s i m S t a r t T i m e S e c , 
                 c o n s t   s t r i n g &   a S t r i n g , 
                 m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   c h a r a c t o r I d s ) ; 
 
         F o r m u l a U n i t I d T y p e   A d d V a r i a b l e U n i t ( 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   s t a t u s V a l u e s , 
                 c o n s t   s t r i n g &   a S t r i n g ) ; 
 
         s t a t i c   v o i d   R e s o l v e O p e r a t i o n ( 
                 c o n s t   s t r i n g &   a S t r i n g , 
                 s t r i n g &   l e f t V a l u e , 
                 s t r i n g &   r i g h t V a l u e , 
                 F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n ) ; 
 
 
         s t a t i c   c o n s t   i n t   R O U T E _ C O S T _ S T A R T   =   N U M B E R _ F O R M U L A _ T Y P E S ; 
         s t a t i c   c o n s t   i n t   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   =   R O U T E _ C O S T _ S T A R T   +   N U M B E R _ A G E N T _ R O U T E _ C O S T S ; 
         s t a t i c   c o n s t   i n t   A G E N T _ S T A T U S _ S T A R T   =   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   +   N U M B E R _ H E A L T H _ O R _ U T I L I T Y _ F A C T O R S ; 
 
         s t a t i c   b o o l   I s R o u t e C o s t ( c o n s t   F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n )   { 
                 r e t u r n   ( R O U T E _ C O S T _ S T A R T   < =   o p e r a t i o n   & &   o p e r a t i o n   <   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T ) ; 
         } 
         s t a t i c   b o o l   I s H e a l t h O r U t i l i t y C o s t ( c o n s t   F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n )   { 
                 r e t u r n   ( H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T   < =   o p e r a t i o n   & &   o p e r a t i o n   <   A G E N T _ S T A T U S _ S T A R T ) ; 
         } 
         s t a t i c   b o o l   I s A g e n t S t a t u s ( c o n s t   F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n )   { 
                 r e t u r n   ( o p e r a t i o n   > =   A G E N T _ S T A T U S _ S T A R T ) ; 
         } 
         s t a t i c   b o o l   M a y B e C o n s t V a l u e ( c o n s t   F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n )   { 
                 r e t u r n   ( o p e r a t i o n   < =   N U M B E R _ F O R M U L A _ T Y P E S ) ; 
         } 
 
         s t a t i c   F o r m u l a O p e r a t i o n T y p e   C o n v e r t T o f F o r m u l a O p e r a t i o n T y p e ( c o n s t   A g e n t S t a t u s I d T y p e &   s t a t u s I d )   { 
                 r e t u r n   F o r m u l a O p e r a t i o n T y p e ( A G E N T _ S T A T U S _ S T A R T   +   s t a t u s I d ) ; 
         } 
 
         s t a t i c   A g e n t R o u t e C o s t T y p e   C o n v e r t T o R o u t e C o s t I d ( c o n s t   F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n )   { 
                 r e t u r n   A g e n t R o u t e C o s t T y p e ( o p e r a t i o n   -   R O U T E _ C O S T _ S T A R T ) ; 
         } 
         s t a t i c   A g e n t H e a l t h O r U t i l i t y F a c t o r T y p e   C o n v e r t T o H e a l t h O r U t i l i t y F a c t o r I d ( c o n s t   F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n )   { 
                 r e t u r n   A g e n t H e a l t h O r U t i l i t y F a c t o r T y p e ( o p e r a t i o n   -   H E A L T H _ O R _ U T I L I T Y _ F A C T O R _ S T A R T ) ; 
         } 
         s t a t i c   A g e n t S t a t u s I d T y p e   C o n v e r t T o f A g e n t S t a t u s I d ( c o n s t   F o r m u l a O p e r a t i o n T y p e &   o p e r a t i o n )   { 
                 r e t u r n   A g e n t S t a t u s I d T y p e ( o p e r a t i o n   -   A G E N T _ S T A T U S _ S T A R T ) ; 
         } 
 } ; 
 
 c l a s s   A g e n t C o n d i t i o n C h e c k e r   { 
 p u b l i c : 
         t y p e d e f     u i n t 8 _ t   C o n d i t i o n P a r a m e t e r T y p e ; 
         e n u m   { 
                 C O N D I T I O N _ P A R A M E T E R _ T I M E , 
                 / / C O N D I T I O N _ P A R A M E T E R _ L O C A T I O N , 
 
                 N U M B E R _ R E S E R V E D _ C O N D I T I O N _ P A R A M E T E R S , 
         } ; 
 
         A g e n t C o n d i t i o n C h e c k e r ( ) 
                 : 
                 C h e c k e r ( & A g e n t C o n d i t i o n C h e c k e r : : C h e c k 0 ) 
         { } 
 
         A g e n t C o n d i t i o n C h e c k e r ( 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   i n i t P a r a m e t e r s , 
                 c o n s t   C o n d i t i o n P a r a m e t e r T y p e &   i n i t P a r a m e t e r T y p e , 
                 c o n s t   d o u b l e   s i n i t S i m S t a r t T i m e S e c , 
                 c o n s t   s t r i n g &   i n i t S t r i n g , 
                 m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e > &   i n i t C h a r a c t o r I d s ) ; 
 
         b o o l   C h e c k ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
 
         s t a t i c   C o n d i t i o n P a r a m e t e r T y p e   C o n v e r t T o P a r a m e t e r T y p e ( c o n s t   A g e n t S t a t u s I d T y p e &   s t a t u s I d )   { 
                 r e t u r n   C o n d i t i o n P a r a m e t e r T y p e ( s t a t u s I d   +   N U M B E R _ R E S E R V E D _ C O N D I T I O N _ P A R A M E T E R S ) ; 
         } 
 
         s t a t i c   A g e n t S t a t u s I d T y p e   C o n v e r t T o S t a t u s I d ( c o n s t   C o n d i t i o n P a r a m e t e r T y p e &   p a r a m e t e r T y p e )   { 
                 r e t u r n   A g e n t S t a t u s I d T y p e ( p a r a m e t e r T y p e   -   N U M B E R _ R E S E R V E D _ C O N D I T I O N _ P A R A M E T E R S ) ; 
         } 
 
 p r i v a t e : 
         C o n d i t i o n P a r a m e t e r T y p e   p a r a m e t e r T y p e ; 
         A g e n t V a l u e F o r m u l a   f o r m u l a ; 
 
         b o o l   ( A g e n t C o n d i t i o n C h e c k e r : : * C h e c k e r ) ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t ; 
 
           b o o l   C h e c k 0 ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t   {   r e t u r n   t r u e ;   } 
           b o o l   C h e c k 1 ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t   {   r e t u r n   ( v 1   = =   v 2 ) ;   } 
           b o o l   C h e c k 2 ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t   {   r e t u r n   ( v 1   ! =   v 2 ) ;   } 
           b o o l   C h e c k 3 ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t   {   r e t u r n   ( v 1   <   v 2 ) ;   } 
           b o o l   C h e c k 4 ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t   {   r e t u r n   ( v 1   < =   v 2 ) ;   } 
           b o o l   C h e c k 5 ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t   {   r e t u r n   ( v 1   >   v 2 ) ;   } 
           b o o l   C h e c k 6 ( c o n s t   d o u b l e &   v 1 ,   c o n s t   d o u b l e &   v 2 )   c o n s t   {   r e t u r n   ( v 1   > =   v 2 ) ;   } 
 } ; 
 
 c l a s s     A g e n t T a s k   { 
 p u b l i c : 
         A g e n t T a s k ( A g e n t P r o f i l e A n d T a s k T a b l e *   i n i t P r o f i l e A n d T a s k T a b l e P t r ) 
                 : 
                 p r o f i l e A n d T a s k T a b l e P t r ( i n i t P r o f i l e A n d T a s k T a b l e P t r ) , 
                 p u r p o s e ( A G E N T _ T A S K _ P U R P O S E _ O T H E R ) , 
                 p r e f e r e d B e h a v i o r ( A G E N T _ B E H A V I O R _ A N Y ) , 
                 b e h a v i o r ( A G E N T _ B E H A V I O R _ A N Y ) , 
                 i n t e r r u p t i o n T y p e ( A G E N T _ B E H A V I O R _ I N T E R R U P T I O N _ N O N E ) 
         { } 
 
         S i m T i m e   G e t S t a r t T i m e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
         S i m T i m e   G e t E n d T i m e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
         S i m T i m e   G e t W a i t T i m e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
         b o o l   S p e c i f i e d A r r i v a l T i m e ( )   c o n s t   {   r e t u r n   ! a r r i v a l T i m e . I s N u l l ( ) ;   } 
 
         b o o l   S a t i s f y C o n d i t i o n ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
 
         v o i d   G e t D e s t i n a t i o n I d ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   b o o l   i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e , 
                 G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
                 b o o l &   i s M u l t i p l e D e s t i n a t i o n s , 
                 A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
 
         b o o l   H a s P a s s V e r t e x S p e c i f i c a t i o n ( )   c o n s t   {   r e t u r n   ! p a s s I n t e r s e c t i o n L o c a t i o n I n f o s . e m p t y ( ) ;   } 
 
         v o i d   G e t P a s s V e r t e x I d s ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 d e q u e < V e r t e x I d T y p e > &   p a s s V e r t e x I d s , 
                 A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
 
         c o n s t   A g e n t A d d i t i o n a l S t a t u s C h a n g e &   G e t A d d i t i o n a S t a t u s C h a n g e ( c o n s t   A g e n t S t a t u s C h a n g e T y p e &   c h a n g e T y p e )   c o n s t   { 
                 t y p e d e f   m a p < A g e n t S t a t u s C h a n g e T y p e ,   A g e n t A d d i t i o n a l S t a t u s C h a n g e > : : c o n s t _ i t e r a t o r   I t e r T y p e ; 
 
                 I t e r T y p e   i t e r   =   a d d i t i o n a l S t a t u s C h a n g e s . f i n d ( c h a n g e T y p e ) ; 
 
                 a s s e r t ( i t e r   ! =   a d d i t i o n a l S t a t u s C h a n g e s . e n d ( ) ) ; 
 
                 r e t u r n   ( * i t e r ) . s e c o n d ; 
         } 
 
         c o n s t   b o o l   H a s S t a t u s C h a n g e ( c o n s t   A g e n t S t a t u s C h a n g e T y p e &   c h a n g e T y p e )   c o n s t   { 
                 r e t u r n   ( a d d i t i o n a l S t a t u s C h a n g e s . f i n d ( c h a n g e T y p e )   ! =   a d d i t i o n a l S t a t u s C h a n g e s . e n d ( ) ) ; 
         } 
 
         c o n s t   A g e n t T a s k P u r p o s e T y p e &   G e t P u r p o s e ( )   c o n s t   {   r e t u r n   p u r p o s e ;   } 
         c o n s t   A g e n t B e h a v i o r T y p e &   G e t P r e f e r e d B e h a v i o r ( )   c o n s t   { 
                 i f   ( b e h a v i o r   ! =   A G E N T _ B E H A V I O R _ A N Y )   { 
                         r e t u r n   b e h a v i o r ; 
                 } 
                 r e t u r n   p r e f e r e d B e h a v i o r ; 
         } 
         c o n s t   A g e n t B e h a v i o r I n t e r r u p t i o n T y p e &   G e t I n t e r r u p t i o n T y p e ( )   c o n s t   {   r e t u r n   i n t e r r u p t i o n T y p e ;   } 
 
         c o n s t   A g e n t B e h a v i o r T y p e &   G e t B e h a v i o r ( )   c o n s t   {   r e t u r n   b e h a v i o r ;   } 
 
         v o i d   G e t T i m e L i n e ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 c o n s t   S i m T i m e &   e a r l y S t a r t T i m e , 
                 T i m e T o S e a r c h R o u t e &   t i m e T o S e a r c h R o u t e )   c o n s t ; 
 
 p r i v a t e : 
         f r i e n d   c l a s s   A g e n t P r o f i l e A n d T a s k T a b l e ; 
         A g e n t P r o f i l e A n d T a s k T a b l e *   p r o f i l e A n d T a s k T a b l e P t r ; 
 
         A g e n t V a l u e F o r m u l a   s t a r t T i m e ; 
         v e c t o r < A g e n t C o n d i t i o n C h e c k e r >   c o n d i t i o n C h e c k e r s ; 
 
         L o c a t i o n I n f o   d e s t i n a t i o n ; 
         d e q u e < L o c a t i o n I n f o >   p a s s I n t e r s e c t i o n L o c a t i o n I n f o s ; 
 
         A g e n t V a l u e F o r m u l a   e n d T i m e ; 
         A g e n t V a l u e F o r m u l a   w a i t T i m e ; 
         A g e n t V a l u e F o r m u l a   a r r i v a l T i m e ; 
         A g e n t V a l u e F o r m u l a   e a r l y A r r i v a l T i m e ; 
         A g e n t V a l u e F o r m u l a   l a t e A r r i v a l T i m e ; 
 
         A g e n t V a l u e F o r m u l a   d e p a r t u r e T i m e ; 
         A g e n t V a l u e F o r m u l a   e a r l y D e p a r t u r e T i m e ; 
         A g e n t V a l u e F o r m u l a   l a t e D e p a r t u r e T i m e ; 
 
         A g e n t T a s k P u r p o s e T y p e   p u r p o s e ; 
         A g e n t B e h a v i o r T y p e   p r e f e r e d B e h a v i o r ; 
         A g e n t B e h a v i o r T y p e   b e h a v i o r ; 
         A g e n t B e h a v i o r I n t e r r u p t i o n T y p e   i n t e r r u p t i o n T y p e ; 
 
         m a p < A g e n t S t a t u s C h a n g e T y p e ,   A g e n t A d d i t i o n a l S t a t u s C h a n g e >   a d d i t i o n a l S t a t u s C h a n g e s ; 
 } ; 
 
 s t r u c t   A g e n t S t a t u s C h a n g e E v e n t   { 
         S i m T i m e   t i m e ; 
 
         A g e n t S t a t u s C h a n g e T y p e   s t a t u s C h a n g e T y p e ; 
         s i z e _ t   s t a t u s C h a n g e N u m b e r ; 
 
         b o o l   o p e r a t o r < ( c o n s t   A g e n t S t a t u s C h a n g e E v e n t &   r i g h t )   c o n s t   { 
                 r e t u r n   t i m e   >   r i g h t . t i m e ; 
         } 
 
         A g e n t S t a t u s C h a n g e E v e n t ( ) 
                 : 
                 t i m e ( Z E R O _ T I M E ) , 
                 s t a t u s C h a n g e T y p e ( A G E N T _ S T A T U S _ C H A N G E _ B A S I C _ T A S K _ S T A R T ) , 
                 s t a t u s C h a n g e N u m b e r ( 0 ) 
         { } 
 
         A g e n t S t a t u s C h a n g e E v e n t ( 
                 c o n s t   S i m T i m e &   i n i t T i m e , 
                 c o n s t   s i z e _ t   s t a t u s C h a n g e N u m b e r , 
                 c o n s t   A g e n t S t a t u s C h a n g e T y p e &   i n i t S t a t u s C h a n g e T y p e ) 
                 : 
                 t i m e ( i n i t T i m e ) , 
                 s t a t u s C h a n g e T y p e ( i n i t S t a t u s C h a n g e T y p e ) , 
                 s t a t u s C h a n g e N u m b e r ( s t a t u s C h a n g e N u m b e r ) 
         { } 
 } ; 
 
 c l a s s   A g e n t T a s k T a b l e   { 
 p u b l i c : 
         A g e n t T a s k T a b l e ( A g e n t P r o f i l e A n d T a s k T a b l e *   i n i t P r o f i l e A n d T a s k T a b l e P t r ) 
                 : 
                 p r o f i l e A n d T a s k T a b l e P t r ( i n i t P r o f i l e A n d T a s k T a b l e P t r ) 
         { } 
 
         s i z e _ t   G e t N u m b e r O f T a s k s ( )   c o n s t   {   r e t u r n   t a s k P t r s . s i z e ( ) ;   } 
         s i z e _ t   G e t N u m b e r O f S t a t u s C h a n g e s ( )   c o n s t   {   r e t u r n   s t a t u s C h a n g e P t r s . s i z e ( ) ;   } 
         s i z e _ t   G e t N u m b e r O f I n t e r r u p t T a s k s ( )   c o n s t   {   r e t u r n   i n t e r r u p t T a s k P t r s . s i z e ( ) ;   } 
 
         v o i d   G e t S t a t u s C h a n g e s ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 p r i o r i t y _ q u e u e _ s t a b l e < A g e n t S t a t u s C h a n g e E v e n t > &   t i m e L i n e S t a t u s C h a n g e E v e n t s )   c o n s t ; 
 
         c o n s t   A g e n t T a s k &   G e t T a s k ( c o n s t   s i z e _ t   t a s k N u m b e r )   c o n s t   {   r e t u r n   * t a s k P t r s . a t ( t a s k N u m b e r ) ;   } 
         c o n s t   A g e n t T a s k &   G e t S t a t u s C h a n g e ( c o n s t   s i z e _ t   s t a t u s C h a n g e N u m b e r )   c o n s t   {   r e t u r n   * s t a t u s C h a n g e P t r s . a t ( s t a t u s C h a n g e N u m b e r ) ;   } 
         c o n s t   A g e n t T a s k &   G e t I n t e r r u p t T a s k ( c o n s t   s i z e _ t   i n t e r r u p t T a s k N u m b e r )   c o n s t   {   r e t u r n   * i n t e r r u p t T a s k P t r s . a t ( i n t e r r u p t T a s k N u m b e r ) ;   } 
 
         v o i d   G e t I n i t i a l L o c a t i o n I d ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   s h a r e d _ p t r < I n o r d e r F i l e C a c h e > &   i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
                 G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
                 b o o l &   i s S p e c i f i e d P o s i t i o n , 
                 V e r t e x &   p o s i t i o n , 
                 A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t ; 
 
         v o i d   G e t L o c a t i o n I d ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   L o c a t i o n I n f o &   l o c a t i o n I n f o , 
                 c o n s t   s h a r e d _ p t r < I n o r d e r F i l e C a c h e > &   i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
                 G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
                 b o o l &   i s M u l t i p l e P o s i t i o n s , 
                 b o o l &   i s S p e c i f i e d P o s i t i o n , 
                 V e r t e x &   p o s i t i o n , 
                 A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t ; 
 
         b o o l   I s E m p t y ( )   c o n s t   {   r e t u r n   t a s k P t r s . e m p t y ( ) ;   } 
 
 p r i v a t e : 
         f r i e n d   c l a s s   A g e n t P r o f i l e A n d T a s k T a b l e ; 
         A g e n t P r o f i l e A n d T a s k T a b l e *   p r o f i l e A n d T a s k T a b l e P t r ; 
 
         L o c a t i o n I n f o   i n i t i a l L o c a t i o n ; 
 
         L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a >   p a r a m e t e r s ; 
         v e c t o r < A g e n t V a l u e F o r m u l a >   r o u t e C o s t F o r m u l a s ; 
 
         v e c t o r < s h a r e d _ p t r < A g e n t T a s k >   >   t a s k P t r s ; 
         v e c t o r < s h a r e d _ p t r < A g e n t T a s k >   >   s t a t u s C h a n g e P t r s ; 
         v e c t o r < s h a r e d _ p t r < A g e n t T a s k >   >   i n t e r r u p t T a s k P t r s ; 
 } ; 
 
 c l a s s   A g e n t P r o f i l e   { 
 p u b l i c : 
         A g e n t P r o f i l e ( 
                 c o n s t   A g e n t P r o f i l e T y p e &   i n i t P r o f i l e T y p e , 
                 c o n s t   s t r i n g &   i n i t P r o f i l e N a m e   =   " " ) ; 
 
         c o n s t   s t r i n g &   G e t P r o f i l e N a m e ( )   c o n s t   {   r e t u r n   p r o f i l e N a m e ;   } 
 
         c o n s t   A g e n t P r o f i l e T y p e &   G e t P r o f i l e T y p e ( )   c o n s t   {   r e t u r n   p r o f i l e T y p e ;   } 
         c o n s t   A g e n t U s e r T y p e &   G e t U s e r T y p e ( )   c o n s t   {   r e t u r n   u s e r T y p e ;   } 
         c o n s t   A g e n t M o b i l i t y C l a s s T y p e &   G e t M o b i l i t y C l a s s ( )   c o n s t   {   r e t u r n   m o b i l i t y C l a s s ;   } 
         c o n s t   A g e n t T i c k e t T y p e &   G e t T i c k e t T y p e ( )   c o n s t   {   r e t u r n   t i c k e t T y p e ;   } 
 
         d o u b l e   G e t H a s C a r R a t i o ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   h a s C a r . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r a n d G e n ) ; 
         } 
 
         d o u b l e   G e t H a s B i c y c l e R a t i o ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t   { 
                 r e t u r n   h a s B i c y c l e . C a l c u l a t e D o u b l e ( r e s o u r c e ,   r a n d G e n ) ; 
         } 
 
         c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   G e t P a r a m e t e r s ( )   c o n s t   {   r e t u r n   p a r a m e t e r s ;   } 
 
         d o u b l e   C a l c u l a t e R o u t e U t i l i t y ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   A g e n t B e h a v i o r T y p e &   b e h a v i o r , 
                 c o n s t   A g e n t H e a l t h O r U t i l i t y F a c t o r &   h e a l t h O r U t i l i t y F a c t o r , 
                 c o n s t   A g e n t R o u t e C o s t &   c o s t )   c o n s t   { 
                 r e t u r n   r o u t e C o s t F o r m u l a s . a t ( b e h a v i o r ) . C a l c u l a t e U t i l i t y ( r e s o u r c e ,   r a n d G e n ,   h e a l t h O r U t i l i t y F a c t o r ,   c o s t ) ; 
         } 
 
         d o u b l e   C a l c u l a t e U t i l i t y 1 ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   A g e n t H e a l t h O r U t i l i t y F a c t o r &   h e a l t h O r U t i l i t y F a c t o r , 
                 c o n s t   A g e n t R o u t e C o s t &   c o s t )   c o n s t   { 
                 r e t u r n   u t i l i t y F o r m u l a 1 . C a l c u l a t e U t i l i t y ( r e s o u r c e ,   r a n d G e n ,   h e a l t h O r U t i l i t y F a c t o r ,   c o s t ) ; 
         } 
         d o u b l e   C a l c u l a t e U t i l i t y 2 ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n , 
                 c o n s t   A g e n t H e a l t h O r U t i l i t y F a c t o r &   h e a l t h O r U t i l i t y F a c t o r , 
                 c o n s t   A g e n t R o u t e C o s t &   c o s t )   c o n s t   { 
                 r e t u r n   u t i l i t y F o r m u l a 2 . C a l c u l a t e U t i l i t y ( r e s o u r c e ,   r a n d G e n ,   h e a l t h O r U t i l i t y F a c t o r ,   c o s t ) ; 
         } 
 
         c o n s t   A g e n t V a l u e F o r m u l a &   G e t P r i m a r y R o u t e C o s t F o r m u l a ( )   c o n s t   { 
                 a s s e r t ( ! r o u t e C o s t F o r m u l a s . e m p t y ( ) ) ; 
                 r e t u r n   r o u t e C o s t F o r m u l a s . f r o n t ( ) ; 
         } 
 
         c o n s t   A g e n t V a l u e F o r m u l a &   G e t U t i l i t y F o r m u l a 1 ( )   c o n s t   {   r e t u r n   u t i l i t y F o r m u l a 1 ;   } 
         c o n s t   A g e n t V a l u e F o r m u l a &   G e t U t i l i t y F o r m u l a 2 ( )   c o n s t   {   r e t u r n   u t i l i t y F o r m u l a 2 ;   } 
 
 p r i v a t e : 
         f r i e n d   c l a s s   A g e n t P r o f i l e A n d T a s k T a b l e ; 
 
         s t r i n g   p r o f i l e N a m e ; 
 
         A g e n t P r o f i l e T y p e   p r o f i l e T y p e ; 
         A g e n t U s e r T y p e   u s e r T y p e ; 
         A g e n t M o b i l i t y C l a s s T y p e   m o b i l i t y C l a s s ; 
         A g e n t T i c k e t T y p e   t i c k e t T y p e ; 
 
         A g e n t V a l u e F o r m u l a   h a s C a r ; 
         A g e n t V a l u e F o r m u l a   h a s B i c y c l e ; 
 
         A g e n t V a l u e F o r m u l a   u t i l i t y F o r m u l a 1 ; 
         A g e n t V a l u e F o r m u l a   u t i l i t y F o r m u l a 2 ; 
 
         L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a >   p a r a m e t e r s ; 
         v e c t o r < A g e n t V a l u e F o r m u l a >   r o u t e C o s t F o r m u l a s ; 
 } ; 
 
 / /   s t r u c t   C h a n g e d A g e n t { 
 / /           i n t   a g e n t I d ; 
 / /           b o o l   C h a n g e d B y M e e t i n g ; 
 
 / /           C h a n g e d A g e n t ( 
 / /           c o n s t   i n t   i n p u t A g e n t I d ) 
 / /           : 
 / /           a g e n t I d ( i n p u t A g e n t I d ) , 
 / /           C h a n g e d B y M e e t i n g ( f a l s e ) 
 / /           { } 
 
 / /           C h a n g e d A g e n t ( ) 
 / /             : 
 / /             a g e n t I d ( 0 ) , 
 / /             C h a n g e d B y M e e t i n g ( t r u e ) 
 / /           { } 
 
 
 / /           v o i d   s e t C h a n g e d M e e t i n g ( b o o l   i n p u t M e e t ) {   C h a n g e d B y M e e t i n g   =   i n p u t M e e t ;   } 
 / /           b o o l   g e t C h a n g e d M e e t i n g ( ) {   r e t u r n   C h a n g e d B y M e e t i n g ;   } 
 / /           v o i d   s e t A g e n t I d ( i n t   i ) {   a g e n t I d   =   i ;   } 
 / /           i n t   g e t A g e n t I d ( ) {   r e t u r n   a g e n t I d ;   } 
 
 / /           v o i d   s e t A g e n t R e s o u r c e ( A g e n t R e s o u r c e   i n p u t R e s o u r c e ) {   a g e n t R e s o u r c e   =   i n p u t R e s o u r c e ;   } 
 / /           A g e n t R e s o u r c e   g e t A g e n t R e s o u r c e ( ) {   r e t u r n   a g e n t R e s o u r c e ;   } 
 
 / /           p r i v a t e : 
 / /             i n t   O b j e c t A g e n t I d ; 
 / /             A g e n t R e s o u r c e   a g e n t R e s o u r c e ; 
 
 / /   } 
 
 c l a s s   A g e n t P r o f i l e A n d T a s k T a b l e   { 
 p u b l i c : 
         A g e n t P r o f i l e A n d T a s k T a b l e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   i n i t P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e > &   i n i t P u b l i c V e h i c l e T a b l e P t r , 
                 c o n s t   s h a r e d _ p t r < G i s S u b s y s t e m > &   i n i t G i s S u b s y s t e m P t r , 
                 c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e ) ; 
 
         v o i d   C o m p l e t e I n i t i a l i z e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   i n i t P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < G i s S u b s y s t e m > &   i n i t G i s S u b s y s t e m P t r , 
                 c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
                 c o n s t   s e t < A g e n t I d T y p e > &   e n t i r e A g e n t I d s ) ; 
 
 
         s h a r e d _ p t r < A g e n t P r o f i l e >   G e t P r o f i l e ( c o n s t   s t r i n g &   p r o f i l e N a m e )   c o n s t ; 
 
         s h a r e d _ p t r < A g e n t T a s k T a b l e >   G e t T a s k T a b l e ( 
                 c o n s t   s t r i n g &   t a s k T a b l e N a m e , 
                 c o n s t   s t r i n g &   p r o f i l e N a m e )   c o n s t ; 
 
         s h a r e d _ p t r < A g e n t T a s k T a b l e >   G e t E m p t y T a s k T a b l e ( )   c o n s t   {   r e t u r n   e m p t y T a s k T a b l e P t r ;   } 
 
         b o o l   C o n t a i n s T a s k ( 
                 c o n s t   s t r i n g &   t a s k T a b l e N a m e , 
                 c o n s t   s t r i n g &   p r o f i l e N a m e )   c o n s t ; 
 
         v e c t o r < s t r i n g >   G e t P r o f i l e T y p e N a m e s ( )   c o n s t ; 
 
         v o i d   G e t L o c a t i o n I d ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s h a r e d _ p t r < M u l t i A g e n t G i s > &   t h e A g e n t G i s P t r , 
                 c o n s t   L o c a t i o n I n f o &   l o c a t i o n I n f o , 
                 c o n s t   s h a r e d _ p t r < I n o r d e r F i l e C a c h e > &   i n i t i a l L o c a t i o n F i l e C a c h e P t r , 
                 c o n s t   b o o l   i g n o r e L a s t P o s i t i o n F r o m C a n d i d a t e , 
                 c o n s t   b o o l   s e a r c h I n t e r s e c t i o n , 
                 G i s P o s i t i o n I d T y p e &   p o s i t i o n I d , 
                 b o o l &   i s M u l t i p l e P o s i t i o n s , 
                 b o o l &   i s S p e c i f i e d P o s i t i o n , 
                 V e r t e x &   p o s i t i o n , 
                 A g e n t R e s o u r c e &   r e s o u r c e , 
                 H i g h Q u a l i t y R a n d o m N u m b e r G e n e r a t o r &   r a n d G e n )   c o n s t ; 
 
         A g e n t V a l u e F o r m u l a   M a k e V a l u e F o r m u l a ( 
                 c o n s t   A g e n t P r o f i l e T y p e &   p r o f i l e T y p e , 
                 c o n s t   s t r i n g &   f o r m u l a ) ; 
 
 p r i v a t e : 
 
         v o i d   L o a d P r o f i l e ( 
                 c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
                 c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
                 c o n s t   s t r i n g &   p r o f i l e F i l e P a t h , 
                 c o n s t   d o u b l e   s t a r t T i m e S e c ) ; 
 
         v o i d   L o a d T a s k T a b l e ( 
                 c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
                 c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
                 c o n s t   s t r i n g &   b e h a v i o r F i l e P a t h , 
                 c o n s t   d o u b l e   s t a r t T i m e S e c , 
                 c o n s t   m a p < s t r i n g ,   s e t < s t r i n g >   > &   a v a i l a b l e T a s k T a b l e s ) ; 
 
         v o i d   A d d T a s k ( 
                 c o n s t   G i s S u b s y s t e m &   t h e G i s S u b s y s t e m , 
                 c o n s t   s t r i n g &   t a s k T a b l e N a m e , 
                 c o n s t   A g e n t R e s o u r c e &   m a s t e r R e s o u r c e , 
                 c o n s t   s t r i n g &   t a s k L i n e , 
                 c o n s t   d o u b l e   s t a r t T i m e S e c , 
                 c o n s t   v e c t o r < p a i r < A g e n t P r o f i l e T y p e ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   >   > &   d e f a u l t P r o f i l e T a s k T a b l e P t r s , 
                 c o n s t   m a p < s t r i n g ,   v e c t o r < G i s P o s i t i o n I d T y p e >   > &   l o c a t i o n G r o u p s ) ; 
 
         s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e >   t h e P u b l i c V e h i c l e T a b l e P t r ; 
 
         L a b e l M a p < A g e n t P r o f i l e T y p e ,   s h a r e d _ p t r < A g e n t P r o f i l e >   >   p r o f i l e P t r s ; 
         m a p < p a i r < s t r i n g ,   A g e n t P r o f i l e T y p e > ,   s h a r e d _ p t r < A g e n t T a s k T a b l e >   >   t a s k T a b l e P t r s ; 
         s h a r e d _ p t r < A g e n t T a s k T a b l e >   e m p t y T a s k T a b l e P t r ; 
 
         m a p < s t r i n g ,   A g e n t C h a r a c t o r I d T y p e >   c h a r a c t o r I d s ; 
 
         m a p < s t r i n g ,   v e c t o r < G i s P o s i t i o n I d T y p e >   >   l o c a t i o n G r o u p s ; 
 } ; 
 
 
 c l a s s   P h y s i c a l D a t a R e c e i v e r :   p u b l i c   S e n s i n g M o d e l : : D a t a R e c e i v e H a n d l e r   { 
 p u b l i c : 
         P h y s i c a l D a t a R e c e i v e r ( c o n s t   A g e n t R e s o u r c e &   i n i t R e s o u r c e ) 
                 : 
                 r e s o u r c e ( i n i t R e s o u r c e ) 
         { } 
 
         v i r t u a l   v o i d   R e c e i v e D a t a ( S e n s i n g S h a r e d I n f o T y p e   b r o a d c a s t D a t a )   { 
                 r e s o u r c e . R e c e i v e P h y s i c a l D a t a ( b r o a d c a s t D a t a ) ; 
         } 
 
 p r i v a t e : 
         A g e n t R e s o u r c e   r e s o u r c e ; 
 } ; 
 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 / /   M u l t i   A g e n t   S i m u l a t o r 
 / / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
 
 c l a s s   P r e S y n c h r o n i z e r   { 
 p u b l i c : 
         v i r t u a l   ~ P r e S y n c h r o n i z e r ( )   { } 
         v i r t u a l   v o i d   S y n c h r o n i z e ( )   c o n s t   =   0 ; 
 } ; 
 
 
 
 
 c l a s s   M u l t i A g e n t S i m u l a t o r   :   p u b l i c   N e t w o r k S i m u l a t o r   { 
 p u b l i c : 
         s t a t i c   c o n s t   b o o l   i s D e b u g M o d e ; 
 
         M u l t i A g e n t S i m u l a t o r ( 
                 c o n s t   s h a r e d _ p t r < P a r a m e t e r D a t a b a s e R e a d e r > &   i n i t P a r a m e t e r D a t a b a s e R e a d e r P t r , 
                 c o n s t   s h a r e d _ p t r < S i m u l a t i o n E n g i n e > &   i n i t S i m u l a t i o n E n g i n e P t r , 
                 c o n s t   R a n d o m N u m b e r G e n e r a t o r S e e d &   i n i t R u n S e e d , 
                 c o n s t   b o o l   i n i t R u n S e q u e n t i a l l y , 
                 c o n s t   b o o l   i n i t I s S c e n a r i o S e t t i n g O u t p u t M o d e , 
                 c o n s t   s t r i n g &   i n i t I n p u t C o n f i g F i l e N a m e , 
                 c o n s t   s t r i n g &   i n i t O u t p u t C o n f i g F i l e N a m e ) ; 
 
         ~ M u l t i A g e n t S i m u l a t o r ( ) ; 
 
         v o i d   R u n S i m u l a t i o n U n t i l ( c o n s t   S i m T i m e &   s n a p s h o t T i m e ) ; 
 
         S i m T i m e   C u r r e n t T i m e ( )   c o n s t   {   r e t u r n   c u r r e n t T i m e ;   } 
         S i m T i m e   N e x t T i m e ( )   c o n s t   {   r e t u r n   c u r r e n t T i m e   +   t i m e S t e p ;   } 
         S i m T i m e   T i m e S t e p ( )   c o n s t   {   r e t u r n   t i m e S t e p ;   } 
 
         S i m T i m e   G e t T a s k S t a r t T i m e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   c o n s t ; 
 
         R a n d o m N u m b e r G e n e r a t o r S e e d   G e t M o b i l i t y S e e d ( )   c o n s t   {   r e t u r n   m o b i l i t y S e e d ;   } 
         u i n t 8 _ t   G e t C u r r e n t S n a p s h o t I d ( )   c o n s t   {   r e t u r n   ( u i n t 8 _ t ) ( c u r r e n t S n a p s h o t I d ) ;   } 
         u i n t 8 _ t   G e t N e x t S n a p s h o t I d ( )   c o n s t   {   r e t u r n   ( c u r r e n t S n a p s h o t I d + 1 ) % N U M B E R _ T I M E S T E P _ S N A P S H O T S ;   } 
         u i n t 8 _ t   G e t P r e v S n a p s h o t I d ( )   c o n s t   { 
                 a s s e r t ( N U M B E R _ T I M E S T E P _ S N A P S H O T S   = =   2 ) ; 
                 r e t u r n   ( c u r r e n t S n a p s h o t I d + 1 ) % N U M B E R _ T I M E S T E P _ S N A P S H O T S ; 
         } 
 
         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   G e t P a r a m e t e r D a t a b a s e R e a d e r ( )   c o n s t   { 
                 r e t u r n   * t h e P a r a m e t e r D a t a b a s e R e a d e r P t r ; 
         } 
 
         v o i d   A d d V e h i c l e ( c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r ) ; 
         v o i d   D e l e t e V e h i c l e ( c o n s t   s h a r e d _ p t r < V e h i c l e > &   v e h i c l e P t r ) ; 
 
         s h a r e d _ p t r < A g e n t V a l u e F o r m u l a >   C r e a t e V a l u e F o r m u l a ( 
                 c o n s t   L a b e l M a p < A g e n t S t a t u s I d T y p e ,   A g e n t V a l u e F o r m u l a > &   s t a t u s V a l u e s , 
                 c o n s t   s t r i n g &   a S t r i n g )   c o n s t ; 
 
         s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e >   G e t P u b l i c V e h i c l e T a b l e ( )   c o n s t   {   r e t u r n   p u b l i c V e h i c l e T a b l e P t r ;   } 
 
         A g e n t R e s o u r c e   G e t M a s t e r B u s A g e n t R e s o u r c e ( )   {   r e t u r n   A g e n t R e s o u r c e ( m a s t e r B u s A g e n t P t r ) ;   } 
         A g e n t R e s o u r c e   G e t M a s t e r T a x i A g e n t R e s o u r c e ( )   {   r e t u r n   A g e n t R e s o u r c e ( m a s t e r T a x i A g e n t P t r ) ;   } 
 
         v o i d   A t t a c h C o m m u n i c a t i o n N o d e ( 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d , 
                 c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) ; 
 
         v o i d   D e t a c h C o m m u n i c a t i o n N o d e ( 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d , 
                 c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   c o m m u n i c a t i o n N o d e P t r ) ; 
 
         v o i d   O u t p u t A g e n t T r a c e s ( ) ; 
 
         v o i d   C r e a t e A p p l i c a t i o n F o r N o d e ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 c o n s t   N o d e I d &   s o u r c e N o d e I d , 
                 c o n s t   I n t e r f a c e O r I n s t a n c e I d &   i n s t a n c e I d , 
                 c o n s t   v e c t o r < s t r i n g > &   p a r a m e t e r L i n e s , 
                 c o n s t   s e t < N o d e I d > &   t a r g e t N o d e I d s ) ; 
 
         v o i d   O u t p u t T r a c e E v e n t ( 
                 c o n s t   N o d e I d &   g i s O b j e c t O r A g e n t I d , 
                 c o n s t   s t r i n g &   e v e n t N a m e , 
                 c o n s t   d o u b l e   v a l u e )   c o n s t ; 
 
         v o i d   O u t p u t S t r i n g T r a c e E v e n t ( 
                 c o n s t   N o d e I d &   g i s O b j e c t O r A g e n t I d , 
                 c o n s t   s t r i n g &   e v e n t N a m e , 
                 c o n s t   s t r i n g &   v a l u e )   c o n s t ; 
 
         v o i d   A d d C o m m u n i c a t i o n N o d e ( 
                 c o n s t   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e > &   a N o d e P t r ) ; 
 
         s h a r e d _ p t r < A g e n t T a s k T a b l e >   G e t T a s k T a b l e ( 
                 c o n s t   s t r i n g &   t a s k T a b l e N a m e , 
                 c o n s t   s t r i n g &   p r o f i l e N a m e )   c o n s t 
                 {   r e t u r n   p r o f i l e A n d T a s k T a b l e P t r - > G e t T a s k T a b l e ( t a s k T a b l e N a m e ,   p r o f i l e N a m e ) ;   } 
 
         v o i d   S e t O w n e r A g e n t ( 
                 c o n s t   A g e n t R e s o u r c e &   r e s o u r c e , 
                 c o n s t   A g e n t I d T y p e &   o w n e r A g e n t I d   =   M A S T E R _ A N Y _ A G E N T _ I D ) ; 
 
         v o i d   R e m o v e O w n e r A g e n t ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e )   {   ( * t h i s ) . S e t O w n e r A g e n t ( r e s o u r c e ) ;   } 
 
         v o i d   R e m o v e O w n e r A g e n t C h a n g e ( c o n s t   A g e n t R e s o u r c e &   r e s o u r c e ) ; 
 
         v o i d   S y n c G i s T o p o l o g y ( )   {   ( * t h i s ) . E x e c u t e T i m e s t e p B a s e d E v e n t ( ) ;   } 
 
         v o i d   A d d T a x i ( c o n s t   s h a r e d _ p t r < T a x i > &   t a x i P t r ) ; 
 
         v o i d   C r e a t e C o m m u n i c a t i o n N o d e A t W a k e u p T i m e F o r ( c o n s t   N o d e I d &   a g e n t I d )   { 
                 c r e a t e C o m m u n i c a t i o n N o d e A t W a k e u p T i m e F o r . i n s e r t ( a g e n t I d ) ; 
         } 
 
         v o i d   O u t p u t T r a c e ( c o n s t   s t r i n g &   a S t r i n g )   c o n s t ; 
 
         v o i d   R e c o r d A s s i g n e d P r o f i l e V a l u e s T o F i l e ( 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d , 
                 c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   p r o f i l e P t r , 
                 c o n s t   m a p < s t r i n g ,   d o u b l e > &   a s s i g n e d V a l u e s , 
                 c o n s t   b o o l   h a s C a r , 
                 c o n s t   b o o l   h a s B i c y c l e )   { 
 
                 p r o f i l e V a l u e O u t p u t S u b s y s t e m . R e c o r d A s s i g n e d P r o f i l e V a l u e s T o F i l e ( a g e n t I d ,   p r o f i l e P t r ,   a s s i g n e d V a l u e s ,   h a s C a r ,   h a s B i c y c l e ) ; 
         } 
 
         s h a r e d _ p t r < I n o r d e r F i l e C a c h e >   G e t I n i t i a l L o c a t i o n F i l e C a c h e P t r ( )   {   r e t u r n   i n i t i a l L o c a t i o n F i l e C a c h e P t r ;   } 
 
 p r o t e c t e d : 
         m a p < N o d e I d ,   S i m T i m e >   w a k e u p T i m e s ; 
 
         b o o l   I s E q u a l T o A g e n t I d ( c o n s t   N o d e I d &   t h e N o d e I d )   c o n s t ; 
         S i m T i m e   G e t W a k e u p T i m e ( c o n s t   N o d e I d &   t h e N o d e I d )   c o n s t ; 
         b o o l   S u p p o r t M u l t i A g e n t ( )   c o n s t   {   r e t u r n   t r u e ;   } 
 
 p r i v a t e : 
 
         v o i d   A d d A g e n t ( c o n s t   s h a r e d _ p t r < A g e n t > &   a g e n t P t r ,   c o n s t   b o o l   w i t h N o d e G e n e r a t i o n   =   t r u e ) ; 
         v o i d   A d d A g e n t W i t h o u t N o d e G e n e r a t i o n ( c o n s t   s h a r e d _ p t r < A g e n t > &   a g e n t P t r )   { 
                 ( * t h i s ) . A d d A g e n t ( a g e n t P t r ,   f a l s e ) ; 
         } 
 
         s h a r e d _ p t r < V e h i c l e N o d e >   C r e a t e V e h i c l e N o d e ( 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d , 
                 c o n s t   V e h i c l e T y p e &   v e h i c l e T y p e ) ; 
 
         s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e >   G e t S i m E n g i n e I n t e r f a c e P t r ( c o n s t   A g e n t I d T y p e &   a g e n t I d ) ; 
 
         v o i d   R e s e r v e V e h i c l e N o d e ( 
                 c o n s t   A g e n t I d T y p e &   a g e n t I d , 
                 c o n s t   V e h i c l e T y p e &   v e h i c l e T y p e ) ; 
 
         v o i d   C h a n g e A g e n t O w n e r I f N e c e s s a r y ( ) ; 
         v o i d   D e l e t e I n a c t i v e A g e n t s ( ) ; 
         v o i d   A d d V e h i c l e ( ) ; 
         v o i d   A d d T r a i n ( c o n s t   v e c t o r < s h a r e d _ p t r < T r a i n >   > &   t r a i n P t r s ) ; 
         v o i d   A d d B u s ( c o n s t   v e c t o r < s h a r e d _ p t r < B u s >   > &   b u s P t r s ) ; 
         v o i d   A d d T a x i ( c o n s t   v e c t o r < p a i r < R a i l R o a d S t a t i o n I d T y p e ,   A g e n t R e s o u r c e >   > &   c a l l e d T a x i s ) ; 
         v o i d   A d d C a r ( ) ; 
 
         v o i d   I n c r e m e n t T i m e S t e p ( ) ; 
         v o i d   I n c r e m e n t T i m e S t e p ( c o n s t   s i z e _ t   t h r e a d N u m b e r ) ; 
 
         v o i d   T a k e P r e S y n c h r o n i z e r ( 
                 s h a r e d _ p t r < P r e S y n c h r o n i z e r > &   p r e S y n c h r o n i z e r P t r , 
                 b o o l &   s u c c e s s ) ; 
 
         v o i d   R e t u r n P r e S y n c h r o n i z e r ( ) ; 
 
         v o i d   R e r o u t e A l l A g e n t s ( ) ; 
 
         v o i d   A d v a n c e T i m e S t e p ( ) ; 
 
         c l a s s   A d v a n c e T i m e S t e p E v e n t   :   p u b l i c   S i m u l a t i o n E v e n t   { 
         p u b l i c : 
                 A d v a n c e T i m e S t e p E v e n t ( M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r )   :   s i m u l a t o r P t r ( i n i t S i m u l a t o r P t r )   { } 
                 v o i d   E x e c u t e E v e n t ( )   {   s i m u l a t o r P t r - > A d v a n c e T i m e S t e p ( ) ;   } 
         p r i v a t e : 
                 M u l t i A g e n t S i m u l a t o r *   s i m u l a t o r P t r ; 
         } ; 
 
         c l a s s   T i m e I n c r e m e n t T h r e a d F u n c t o r   { 
         p u b l i c : 
                 T i m e I n c r e m e n t T h r e a d F u n c t o r ( 
                         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r , 
                         c o n s t   s i z e _ t   i n i t T h r e a d N u m b e r ) 
                         : 
                         s i m u l a t o r P t r ( i n i t S i m u l a t o r P t r ) , 
                         t h r e a d N u m b e r ( i n i t T h r e a d N u m b e r ) 
                 { } 
                 v o i d   o p e r a t o r ( ) ( )   {   s i m u l a t o r P t r - > I n c r e m e n t T i m e S t e p ( t h r e a d N u m b e r ) ;   } 
         p r i v a t e : 
                 M u l t i A g e n t S i m u l a t o r *   s i m u l a t o r P t r ; 
                 s i z e _ t   t h r e a d N u m b e r ; 
         } ; 
 
         s i z e _ t   c u r r e n t S n a p s h o t I d ; 
         S i m T i m e   c u r r e n t T i m e ; 
         S i m T i m e   t i m e S t e p ; 
         b o o l   i s S i m u l a t i o n D o n e ; 
 
         b o o l   i s S c e n a r i o S e t t i n g O u t p u t M o d e ; 
         s t r i n g   i n p u t C o n f i g F i l e N a m e ; 
         s t r i n g   o u t p u t C o n f i g F i l e N a m e ; 
 
         s t a t i c   c o n s t   s t r i n g   m o d e l N a m e ; 
 
         s t r u c t   O w n e r C h a n g e E v e n t   { 
                 A g e n t I d T y p e   a g e n t I d ; 
                 A g e n t I d T y p e   o w n e r I d ; 
 
                 O w n e r C h a n g e E v e n t ( ) 
                         : 
                         a g e n t I d ( M A S T E R _ A N Y _ A G E N T _ I D ) , 
                         o w n e r I d ( M A S T E R _ A N Y _ A G E N T _ I D ) 
                 { } 
 
                 O w n e r C h a n g e E v e n t ( 
                         c o n s t   A g e n t I d T y p e &   i n i t A g e n t I d , 
                         c o n s t   A g e n t I d T y p e &   i n i t O w n e r I d ) 
                         : 
                         a g e n t I d ( i n i t A g e n t I d ) , 
                         o w n e r I d ( i n i t O w n e r I d ) 
                 { } 
         } ; 
 
         s t r u c t   D y n a m i c A p p l u c a t i o n D a t a   { 
                 N o d e I d   s o u r c e N o d e I d ; 
                 I n t e r f a c e O r I n s t a n c e I d   i n s t a n c e I d ; 
                 v e c t o r < s t r i n g >   p a r a m e t e r L i n e s ; 
                 s e t < N o d e I d >   t a r g e t N o d e I d s ; 
 
                 D y n a m i c A p p l u c a t i o n D a t a ( 
                         c o n s t   N o d e I d &   i n i t S o u r c e N o d e I d , 
                         c o n s t   I n t e r f a c e O r I n s t a n c e I d &   i n i t I n s t a n c e I d , 
                         c o n s t   v e c t o r < s t r i n g > &   i n i t P a r a m e t e r L i n e s , 
                         c o n s t   s e t < N o d e I d > &   i n i t T a r g e t N o d e I d s ) 
                         : 
                         s o u r c e N o d e I d ( i n i t S o u r c e N o d e I d ) , 
                         i n s t a n c e I d ( i n i t I n s t a n c e I d ) , 
                         p a r a m e t e r L i n e s ( i n i t P a r a m e t e r L i n e s ) , 
                         t a r g e t N o d e I d s ( i n i t T a r g e t N o d e I d s ) 
                 { } 
         } ; 
 
         v o i d   S y n c A p p l i c a t i o n C r e a t i o n ( ) ; 
         v o i d   G e n e r a t e D y n a m i c A p p l i c a t i o n ( c o n s t   D y n a m i c A p p l u c a t i o n D a t a &   d y n a m i c A p p l i c a t i o n D a t a ) ; 
 
         c l a s s   A p p l i c a t i o n C r e a t i o n S y n c h r o n i z e r   :   p u b l i c   P r e S y n c h r o n i z e r   { 
         p u b l i c : 
                 A p p l i c a t i o n C r e a t i o n S y n c h r o n i z e r ( M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r P t r ) 
                         : 
                         s i m u l a t o r P t r ( i n i t S i m u l a t o r P t r ) 
                 { } 
                 v i r t u a l   v o i d   S y n c h r o n i z e ( )   c o n s t   { 
                         s i m u l a t o r P t r - > S y n c A p p l i c a t i o n C r e a t i o n ( ) ; 
                 } 
         p r i v a t e : 
                 M u l t i A g e n t S i m u l a t o r *   s i m u l a t o r P t r ; 
         } ; 
 
         c l a s s   P r o f i l e V a l u e O u t p u t S u b s y s t e m   { 
         p u b l i c : 
                 P r o f i l e V a l u e O u t p u t S u b s y s t e m ( 
                         c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   i n i t P a r a m e t e r D a t a b a s e R e a d e r ) ; 
 
                 v o i d   R e c o r d A s s i g n e d P r o f i l e V a l u e s T o F i l e ( 
                         c o n s t   A g e n t I d T y p e &   a g e n t I d , 
                         c o n s t   s h a r e d _ p t r < A g e n t P r o f i l e > &   p r o f i l e P t r , 
                         c o n s t   m a p < s t r i n g ,   d o u b l e > &   a s s i g n e d V a l u e s , 
                         c o n s t   b o o l   h a s C a r , 
                         c o n s t   b o o l   h a s B i c y c l e ) ; 
 
         p r i v a t e : 
                 o f s t r e a m   p r o f i l e V a l u e O u t p u t F i l e ; 
         } ; 
 
         P r o f i l e V a l u e O u t p u t S u b s y s t e m   p r o f i l e V a l u e O u t p u t S u b s y s t e m ; 
 
         s h a r e d _ p t r < b o o s t : : t h r e a d >   t i m e I n c r e m e n t T h r e a d P t r ; 
         q u e u e < A g e n t I d T y p e >   d e l e t e N o d e I d s ; 
         l i s t < s h a r e d _ p t r < A g e n t >   >   a g e n t P t r s ; 
         q u e u e < s h a r e d _ p t r < P r e S y n c h r o n i z e r >   >   t o o k S y n c h r o n i z e r P t r s ; 
         m a p < A g e n t I d T y p e ,   l i s t < s h a r e d _ p t r < A g e n t >   > : : i t e r a t o r >   i t e r T o A g e n t L i s t ; 
 
         l i s t < s h a r e d _ p t r < V e h i c l e >   >   n e w l y A d d e d V e h i c l e P t r s ; 
         m a p < A g e n t I d T y p e ,   O w n e r C h a n g e E v e n t >   o w n e r C h a n g e E v e n t s ; 
         v e c t o r < D y n a m i c A p p l u c a t i o n D a t a >   d y n a m i c A p p l i c a t i o n D a t a s ; 
 
         s t a t i c   c o n s t   i n t   S E E D _ H A S H I N G _ I N P U T   =   3 5 2 0 1 6 3 ; 
 
         v e c t o r < q u e u e < s h a r e d _ p t r < V e h i c l e N o d e >   >   >   r e s e r v e d V e h i c l e N o d e P t r s ; 
 
         s h a r e d _ p t r < M u l t i A g e n t G i s >   t h e A g e n t G i s P t r ; 
 
         s h a r e d _ p t r < A g e n t >   m a s t e r A n y A g e n t P t r ; 
         s h a r e d _ p t r < P u b l i c V e h i c l e T a b l e >   p u b l i c V e h i c l e T a b l e P t r ; 
         u n i q u e _ p t r < A g e n t P r o f i l e A n d T a s k T a b l e >   p r o f i l e A n d T a s k T a b l e P t r ; 
 
         s h a r e d _ p t r < A g e n t >   m a s t e r B u s A g e n t P t r ; 
         s h a r e d _ p t r < A g e n t >   m a s t e r T a x i A g e n t P t r ; 
 
         s h a r e d _ p t r < A g e n t R o u t e S e a r c h S u b s y s t e m >   t h e R o u t e S e a r c h S u b s y s t e m P t r ; 
 
         s h a r e d _ p t r < S i m u l a t i o n E n g i n e I n t e r f a c e >   t h e S i m u l a t i o n R u n I n t e r f a c e P t r ; 
 
         s h a r e d _ p t r < I n o r d e r F i l e C a c h e >   i n i t i a l L o c a t i o n F i l e C a c h e P t r ; 
 
         s t r u c t   A g e n t W a k e u p E n t r y   { 
                 S i m T i m e   t i m e ; 
                 s h a r e d _ p t r < A g e n t >   a g e n t P t r ; 
 
                 A g e n t W a k e u p E n t r y ( ) 
                         : 
                         t i m e ( ) , 
                         a g e n t P t r ( ) 
                 { } 
 
                 A g e n t W a k e u p E n t r y ( 
                         c o n s t   S i m T i m e &   i n i t T i m e , 
                         c o n s t   s h a r e d _ p t r < A g e n t > &   i n i t A g e n t P t r ) 
                         : 
                         t i m e ( i n i t T i m e ) , 
                         a g e n t P t r ( i n i t A g e n t P t r ) 
                 { } 
 
                 b o o l   o p e r a t o r < ( c o n s t   A g e n t W a k e u p E n t r y &   r i g h t )   c o n s t   { 
                         r e t u r n   ( ( t i m e   >   r i g h t . t i m e )   | | 
                                         ( ( t i m e   = =   r i g h t . t i m e )   & & 
                                           ( a g e n t P t r - > G e t A g e n t I d ( )   >   r i g h t . a g e n t P t r - > G e t A g e n t I d ( ) ) ) ) ; 
                 } 
         } ; 
 
         s e t < A g e n t I d T y p e >   e n t i r e A g e n t I d s ; 
         p r i o r i t y _ q u e u e _ s t a b l e < A g e n t W a k e u p E n t r y >   a g e n t W a k e u p Q u e u e ; 
 
         s e t < A g e n t I d T y p e >   n e w l y A d d e d A g e n t I d s ; 
 
         m a p < A g e n t I d T y p e ,   l i s t < s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   >   >   c o m m u n i c a t i o n N o d e P t r s W a i t i n g A g e n t C r e a t i o n ; 
         m a p < A g e n t I d T y p e ,   s h a r e d _ p t r < A g e n t C o m m u n i c a t i o n N o d e >   >   s y n c h r o n i z e d N o d e P t r s ; 
         s e t < A g e n t I d T y p e >   c r e a t e C o m m u n i c a t i o n N o d e A t W a k e u p T i m e F o r ; 
 
         c l a s s   M u l t i A g e n t G i s C h a n g e E v e n t H a n d l e r   :   p u b l i c   G i s S u b s y s t e m : : G i s C h a n g e E v e n t H a n d l e r   { 
         p u b l i c : 
                 M u l t i A g e n t G i s C h a n g e E v e n t H a n d l e r ( 
                         M u l t i A g e n t S i m u l a t o r *   i n i t S i m u l a t o r )   :   s i m u l a t o r ( i n i t S i m u l a t o r ) 
                 { } 
 
                 v i r t u a l   v o i d   G i s I n f o r m a t i o n C h a n g e d ( )   { 
                         s i m u l a t o r - > R e r o u t e A l l A g e n t s ( ) ; 
                 } 
         p r i v a t e : 
                 M u l t i A g e n t S i m u l a t o r *   s i m u l a t o r ; 
         } ; 
 
         / /   S c e n a r i o   o u t p u t   f u n c t i o n s : 
 
         v o i d   O u t p u t S c e n a r i o S e t t i n g T o C o n f i g ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s e t < A g e n t I d T y p e > &   a g e n t I d s , 
                 c o n s t   v e c t o r < s h a r e d _ p t r < A g e n t >   > &   a l l H u m a n A g e n t P t r s , 
                 c o n s t   l i s t < s h a r e d _ p t r < V e h i c l e >   > &   a l l P r i v a t e C a r P t r s ) ; 
 
         v o i d   O u t p u t A l l H u m a n A g e n t I n i t i a l L o c a t i o n T o P o s F i l e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s e t < A g e n t I d T y p e > &   a g e n t I d s , 
                 c o n s t   v e c t o r < s h a r e d _ p t r < A g e n t >   > &   a l l H u m a n A g e n t P t r s , 
                 c o n s t   l i s t < s h a r e d _ p t r < V e h i c l e >   > &   a l l P r i v a t e C a r P t r s , 
                 c o n s t   s t r i n g &   o u t p u t F i l e N a m e ) ; 
 
         v o i d   O v e r w r i t e G i s S h a p e F i l e ( 
                 c o n s t   P a r a m e t e r D a t a b a s e R e a d e r &   t h e P a r a m e t e r D a t a b a s e R e a d e r , 
                 c o n s t   s t r i n g &   d e s t S h a p e D i r N a m e , 
                 v e c t o r < s t r i n g > &   o u t p u t S h a p e F i l e N a m e s ) ; 
 
         v o i d   O v e r w r i t e B e h a v i o r F i l e W i t h P r e s e n t I n i t i a l L o c a t i o n ( 
                 c o n s t   s t r i n g &   o r i g B e h a v i o r F i l e N a m e , 
                 c o n s t   s t r i n g &   d e s t B e h a v i o r F i l e N a m e ) ; 
 
 } ; / / M u l t i a g e n t S i m u l a t o r / / 
 
 
 i n l i n e 
 v o i d   M u l t i A g e n t S i m u l a t o r : : O u t p u t T r a c e ( c o n s t   s t r i n g &   a S t r i n g )   c o n s t 
 { 
         i f   ( i s D e b u g M o d e )   { 
                 c o n s t   S i m T i m e   t i m e   =   ( * t h i s ) . C u r r e n t T i m e ( ) ; 
                 c o u t   < <   C o n v e r t T i m e T o S t r i n g S e c s ( t i m e )   < <   " : [ e n g i n e ]   "   < <   a S t r i n g   < <   e n d l ; 
         } / / i f / / 
 } 
 
 
 i n l i n e 
 v o i d   A g e n t : : O u t p u t T r a c e ( c o n s t   s t r i n g &   a S t r i n g )   c o n s t 
 { 
         i f   ( M u l t i A g e n t S i m u l a t o r : : i s D e b u g M o d e )   { 
                 c o n s t   S i m T i m e   t i m e   =   s i m u l a t o r P t r - > C u r r e n t T i m e ( ) ; 
                 c o u t   < <   C o n v e r t T i m e T o S t r i n g S e c s ( t i m e )   < <   " : [ "   < <     s t d : : s e t w ( 4 ) 
                           < <   a g e n t I d   < <   " ( v "   < <   l a s t V e r t e x I d   < <   " ) ]   "   < <   a S t r i n g   < <   e n d l ; 
         } / / i f / / 
 } 
 
 
 } / / n a m e s p a c e 
 
 # e n d i f 
 